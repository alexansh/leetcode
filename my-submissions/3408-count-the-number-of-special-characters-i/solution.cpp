class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;

        for (char c : word) {
            if (islower(c))
                lower.insert(c);
            else
                upper.insert(c);
        }

        int count = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            if (lower.count(c) && upper.count(toupper(c))) {
                count++;
            }
        }

        return count;
    }
};
