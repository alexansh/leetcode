class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int x : nums) {
            sum = (sum + x) % k;

            if (sum < 0)
                sum += k;

            ans += freq[sum];
            freq[sum]++;
        }

        return ans;
    }
};
