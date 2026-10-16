
class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& cur,
               vector<bool>& used) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1]
                && !used[i - 1])
                continue;

            used[i] = true;
            cur.push_back(nums[i]);

            solve(nums, cur, used);

            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<bool> used(nums.size(), false);

        solve(nums, cur, used);
        return ans;
    }
};

