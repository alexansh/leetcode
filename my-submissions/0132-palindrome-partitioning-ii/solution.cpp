class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> cuts(n);
        
        for (int i = 0; i < n; ++i) {
            int minCuts = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    minCuts = (j == 0) ? 0 : min(minCuts, cuts[j - 1] + 1);
                }
            }
            cuts[i] = minCuts;
        }
        
        return cuts[n - 1];
    }
};
