class Solution {
public:
    bool possible(vector<int>& nums, int k, long long limit) {
        int parts = 1;
        long long sum = 0;

        for (int x : nums) {
            if (sum + x > limit) {
                parts++;
                sum = x;
            } else {
                sum += x;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;

        for (int x : nums) {
            low = max(low, (long long)x);
            high += x;
        }

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (possible(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
