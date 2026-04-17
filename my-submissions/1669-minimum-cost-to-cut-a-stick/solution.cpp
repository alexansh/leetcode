class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));
        
        for (int len = 2; len < c; len++) {
            for (int i = 0; i + len < c; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                                   cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }
        
        return dp[0][c - 1];
    }
};
