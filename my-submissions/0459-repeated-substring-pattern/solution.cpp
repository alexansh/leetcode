class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0)
                continue;

            string pattern = s.substr(0, len);
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (s[i] != pattern[i % len]) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                return true;
        }

        return false;
    }
};
