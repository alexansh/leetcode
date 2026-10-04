class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        for (int top = 0; top < m; top++) {
            vector<int> sum(n, 0);

            for (int bottom = top; bottom < m; bottom++) {
                for (int col = 0; col < n; col++)
                    sum[col] += matrix[bottom][col];

                unordered_map<int, int> mp;
                mp[0] = 1;

                int prefix = 0;

                for (int x : sum) {
                    prefix += x;

                    if (mp.count(prefix - target))
                        ans += mp[prefix - target];

                    mp[prefix]++;
                }
            }
        }

        return ans;
    }
};
