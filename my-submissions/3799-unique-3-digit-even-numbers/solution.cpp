class Solution {
public:
    set<int> st;
    bool used[10] = {};

    void solve(vector<int>& digits, int pos, int num) {

        // 3-digit number formed
        if (pos == 3) {
            st.insert(num);
            return;
        }

        for (int i = 0; i < digits.size(); i++) {

            if (used[i])
                continue;

            // No leading zero
            if (pos == 0 && digits[i] == 0)
                continue;

            // Last digit must be even
            if (pos == 2 && digits[i] % 2 != 0)
                continue;

            used[i] = true;

            solve(digits, pos + 1,
                  num * 10 + digits[i]);

            // Backtrack
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {

        solve(digits, 0, 0);

        return st.size();
    }
};
