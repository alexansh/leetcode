class Solution {
public:
    vector<vector<int>> dp;

    int editDis(string &x, string &y, int m, int n) {

        if (m == 0)
            return n;

        if (n == 0)
            return m;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (x[m - 1] == y[n - 1]) {
            return dp[m][n] = editDis(x, y, m - 1, n - 1);
        }

        return dp[m][n] = 1 + min({
            editDis(x, y, m, n - 1),     
            editDis(x, y, m - 1, n),      
            editDis(x, y, m - 1, n - 1)   
        });
    }

    int minDistance(string word1, string word2) {

        dp.assign(word1.size() + 1,
                  vector<int>(word2.size() + 1, -1));

        return editDis(word1, word2, word1.size(), word2.size());
    }
};
