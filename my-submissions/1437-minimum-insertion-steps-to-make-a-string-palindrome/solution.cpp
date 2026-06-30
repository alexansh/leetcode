class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }

    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int lps = longestCommonSubsequence(s, rev);

        return s.size() - lps;
    }
};
