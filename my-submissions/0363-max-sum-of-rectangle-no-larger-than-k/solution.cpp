class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        for (int left = 0; left < n; left++) {
            vector<int> sum(m, 0);

            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++)
                    sum[i] += matrix[i][right];

                set<int> s;
                s.insert(0);

                int prefix = 0;

                for (int x : sum) {
                    prefix += x;

                    auto it = s.lower_bound(prefix - k);

                    if (it != s.end())
                        ans = max(ans, prefix - *it);

                    s.insert(prefix);
                }
            }
        }

        return ans;
    }
};
