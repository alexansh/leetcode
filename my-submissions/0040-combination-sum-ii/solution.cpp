class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& curr, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // pruning
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // move to next index (i+1 → use once only)
            solve(i + 1, candidates, target - candidates[i], curr, ans);

            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates, target, curr, ans);

        return ans;
    }
};
