class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;

        // Store all prefixes from arr1
        for (int num : arr1) {
            string s = to_string(num);
            string temp = "";

            for (char c : s) {
                temp += c;
                prefixes.insert(temp);
            }
        }

        int ans = 0;

        // Check prefixes in arr2
        for (int num : arr2) {
            string s = to_string(num);
            string temp = "";

            for (int i = 0; i < s.size(); i++) {
                temp += s[i];

                if (prefixes.count(temp)) {
                    ans = max(ans, i + 1);
                }
            }
        }

        return ans;
    }
};
