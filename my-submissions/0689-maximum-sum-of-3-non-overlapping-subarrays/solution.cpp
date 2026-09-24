class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> sum(n + 1, 0);

        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + nums[i];

        vector<int> left(n), right(n);

        int best = 0;

        for (int i = k; i <= n - k; i++) {
            int curr = sum[i] - sum[i - k];

            if (curr > sum[best + k] - sum[best])
                best = i - k;

            left[i] = best;
        }

        best = n - k;

        for (int i = n - k; i >= k; i--) {
            int curr = sum[i + k] - sum[i];

            if (curr >= sum[best + k] - sum[best])
                best = i;

            right[i] = best;
        }

        vector<int> ans;
        int maxSum = 0;

        for (int mid = k; mid <= n - 2 * k; mid++) {
            int l = left[mid];
            int r = right[mid + k];

            int total = (sum[l + k] - sum[l]) +
                        (sum[mid + k] - sum[mid]) +
                        (sum[r + k] - sum[r]);

            if (total > maxSum) {
                maxSum = total;
                ans = {l, mid, r};
            }
        }

        return ans;
    }
};
