class Solution {
public:
    vector<vector<int>> rects;
    vector<long long> prefix;
    long long total = 0;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;

        for (auto& r : rects) {
            long long points = (long long)(r[2] - r[0] + 1) *
                               (r[3] - r[1] + 1);

            total += points;
            prefix.push_back(total);
        }
    }

    vector<int> pick() {
        long long x = rand() % total + 1;

        int idx = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();

        auto& r = rects[idx];

        int px = r[0] + rand() % (r[2] - r[0] + 1);
        int py = r[1] + rand() % (r[3] - r[1] + 1);

        return {px, py};
    }
};
