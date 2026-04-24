class Solution {
public:
    string reverseWords(string s) {
        string word, result;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') continue;
            
            int j = i;
            while (j >= 0 && s[j] != ' ') j--;
            
            result += s.substr(j + 1, i - j);
            result += " ";
            i = j;
        }
        
        if (!result.empty()) result.pop_back();
        return result;
    }
};
