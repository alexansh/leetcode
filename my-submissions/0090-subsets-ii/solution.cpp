class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {

            // skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);

            solve(i + 1, nums, curr, ans);

            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, nums, curr, ans);

        return ans;
    }
};
