class Solution {
public:
    vector<int> ans;
    int cnt[10] = {};

    void solve(int num, int len) {

        // Formed a 3-digit number
        if (len == 3) {
            if (num % 2 == 0)
                ans.push_back(num);
            return;
        }

        for (int d = 0; d <= 9; d++) {

            // Digit not available
            if (cnt[d] == 0)
                continue;

            // First digit cannot be zero
            if (len == 0 && d == 0)
                continue;

            // Last digit must be even
            if (len == 2 && d % 2 != 0)
                continue;

            cnt[d]--;

            solve(num * 10 + d, len + 1);

            cnt[d]++;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {

        for (int d : digits)
            cnt[d]++;

        solve(0, 0);

        return ans;
    }
};
