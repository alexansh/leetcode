class Solution {
public:
    long long dp[20][11][11][2][2];
    long long cnt[20][11][11][2][2];
    string s;

    pair<long long,long long> dfs(int pos, int prev1, int prev2,
                                  bool started, bool tight) {

        if (pos == s.size()) {
            return {1, 0};
        }

        long long &ways = cnt[pos][prev1][prev2][started][tight];
        long long &waves = dp[pos][prev1][prev2][started][tight];

        if (ways != -1) {
            return {ways, waves};
        }

        ways = 0;
        waves = 0;

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                auto [c, w] = dfs(pos + 1, 10, 10, false, ntight);
                ways += c;
                waves += w;
            } else {

                auto [c, w] = dfs(
                    pos + 1,
                    d,
                    prev1,
                    true,
                    ntight
                );

                long long add = 0;

                if (started && prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = c;
                    }
                }

                ways += c;
                waves += w + add;
            }
        }

        return {ways, waves};
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);

        memset(dp, -1, sizeof(dp));
        memset(cnt, -1, sizeof(cnt));

        return dfs(0, 10, 10, false, true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
