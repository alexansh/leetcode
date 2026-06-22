class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> adj(n);

        for(auto &path : paths) {
            int u = path[0] - 1;
            int v = path[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> flower(n, 0);

        for(int garden = 0; garden < n; garden++) {

            bool used[5] = {false};

            for(int neighbor : adj[garden]) {
                used[flower[neighbor]] = true;
            }

            for(int color = 1; color <= 4; color++) {
                if(!used[color]) {
                    flower[garden] = color;
                    break;
                }
            }
        }

        return flower;
    }
};
