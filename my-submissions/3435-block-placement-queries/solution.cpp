class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int MAXX = 50000;

        set<int> pos = {0, MAXX};

        vector<int> seg(4 * (MAXX + 1), 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int idx, int val) -> void {
            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (idx <= mid)
                self(self, node * 2, l, mid, idx, val);
            else
                self(self, node * 2 + 1, mid + 1, r, idx, val);

            seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
        };

        auto query = [&](auto&& self, int node, int l, int r,
                         int ql, int qr) -> int {

            if (ql > r || qr < l)
                return 0;

            if (ql <= l && r <= qr)
                return seg[node];

            int mid = (l + r) / 2;

            return max(
                self(self, node * 2, l, mid, ql, qr),
                self(self, node * 2 + 1, mid + 1, r, ql, qr)
            );
        };

        update(update, 1, 0, MAXX, MAXX, MAXX);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                auto it = pos.upper_bound(x);

                int r = *it;
                int l = *prev(it);

                update(update, 1, 0, MAXX, r, r - x);
                update(update, 1, 0, MAXX, x, x - l);

                pos.insert(x);
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = pos.upper_bound(x);

                int l = *prev(it);

                int best = query(query, 1, 0, MAXX, 0, l);

                best = max(best, x - l);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};
