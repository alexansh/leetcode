class Solution {
public:
    vector<string> ans;

    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(int index, string &digits, string current) {

        // Base case
        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for(char ch : mp[digit]) {
            solve(index + 1, digits, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        solve(0, digits, "");

        return ans;
    }
};
