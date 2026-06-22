class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();

        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0)
            return 0;

        int gold = grid[r][c];

        // Mark as visited
        grid[r][c] = 0;

        int up    = dfs(grid, r - 1, c);
        int down  = dfs(grid, r + 1, c);
        int left  = dfs(grid, r, c - 1);
        int right = dfs(grid, r, c + 1);

        // Backtrack
        grid[r][c] = gold;

        return gold + max({up, down, left, right});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};
