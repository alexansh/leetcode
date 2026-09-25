class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int l = (i + 1) % n;
            int r = (i - nums[i] + n) % n;

            if (l <= r) {
                diff[l]++;
                diff[r + 1]--;
            } else {
                diff[l]++;
                diff[n]--;
                diff[0]++;
                diff[r + 1]--;
            }
        }

        int score = 0;
        int best = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            score += diff[i];

            if (score > best) {
                best = score;
                ans = i;
            }
        }

        return ans;
    }
};
