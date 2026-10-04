class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        int flips = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            flips ^= diff[i];

            if (nums[i] ^ flips == 0) {
                if (i + k > n)
                    return -1;

                flips ^= 1;
                diff[i + k] ^= 1;
                ans++;
            }
        }

        return ans;
    }
};
