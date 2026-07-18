class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        
        for (int i = 1; i < n; ++i) {
            int incProfit = jobs[i][2];
            int l = 0, r = i - 1, latestNonOverlap = -1;
            
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (jobs[mid][0] <= jobs[i][1]) {
                    latestNonOverlap = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            if (latestNonOverlap != -1) {
                incProfit += dp[latestNonOverlap];
            }
            dp[i] = max(dp[i - 1], incProfit);
        }
        
        return dp[n - 1];
    }
};
