class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        // Step 1: sort
        sort(intervals.begin(), intervals.end());

        for (auto& interval : intervals) {
            if (ans.empty() || interval[0] > ans.back()[1]) {
                // no overlap
                ans.push_back(interval);
            } else {
                // overlap → merge
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};
