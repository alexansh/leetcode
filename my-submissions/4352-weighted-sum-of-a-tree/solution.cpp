class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        
        vector<int> depth(n, 0);
        depth[0] = 1;
        int h = 1;
        
        vector<int> q;
        q.push_back(0);
        int head = 0;
        
        while (head < q.size()) {
            int u = q[head++];
            if (depth[u] > h) {
                h = depth[u];
            }
            for (int v : adj[u]) {
                depth[v] = depth[u] + 1;
                q.push_back(v);
            }
        }
        
        vector<int> malviretho = nums;
        long long totalWeight = 0;
        
        for (int i = 0; i < n; i++) {
            totalWeight += (long long)malviretho[i] * (h - depth[i] + 1);
        }
        
        return totalWeight;
    }
};
