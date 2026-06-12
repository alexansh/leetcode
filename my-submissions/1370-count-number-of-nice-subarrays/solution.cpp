class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int oddCount = 0;
        int ans = 0;

        for (int num : nums) {
            oddCount += (num % 2);

            if (mp.find(oddCount - k) != mp.end()) {
                ans += mp[oddCount - k];
            }

            mp[oddCount]++;
        }

        return ans;
    }
};
