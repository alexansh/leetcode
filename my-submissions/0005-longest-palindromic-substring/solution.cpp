class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;

        string lps = "";
        
        for (int i = 0; i < s.length(); i++) {

            
            int low = i, high = i;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                low--;
                high++;
            }
            string palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > lps.length()) {
                lps = palindrome;
            }

            
            low = i;
            high = i + 1;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                low--;
                high++;
            }
            palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > lps.length()) {
                lps = palindrome;
            }
        }

        return lps;
    }
};

