class Solution {
public:
    vector<string> ans;

    void solve(int index,
               string &s,
               unordered_set<string> &dict,
               string curr) {

        if (index == s.size()) {
            curr.pop_back(); 
            ans.push_back(curr);
            return;
        }

        string word = "";

        for (int i = index; i < s.size(); i++) {

            word += s[i];

            if (dict.count(word)) {
                solve(i + 1,
                      s,
                      dict,
                      curr + word + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(),
                                   wordDict.end());

        solve(0, s, dict, "");

        return ans;
    }
};
