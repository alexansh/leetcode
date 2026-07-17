class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> maxLenEndingWith(26, 0);
        int currentMaxLen = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1) {
                currentMaxLen++;
            } else {
                currentMaxLen = 1;
            }
            
            int index = s[i] - 'a';
            maxLenEndingWith[index] = max(maxLenEndingWith[index], currentMaxLen);
        }
        
        int totalUniqueSubstrings = 0;
        for (int len : maxLenEndingWith) {
            totalUniqueSubstrings += len;
        }
        
        return totalUniqueSubstrings;
    }
};
