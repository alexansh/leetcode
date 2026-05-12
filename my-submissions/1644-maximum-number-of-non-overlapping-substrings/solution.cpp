class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> first(26, INT_MAX), last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> intervals;

        for (int i = 0; i < s.size(); i++) {

            if (i != first[s[i] - 'a'])
                continue;

            int end = last[s[i] - 'a'];
            bool valid = true;

            for (int j = i; j <= end; j++) {

                if (first[s[j] - 'a'] < i) {
                    valid = false;
                    break;
                }

                end = max(end, last[s[j] - 'a']);
            }

            if (valid)
                intervals.push_back({end, i});
        }

        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int prevEnd = -1;

        for (auto &[end, start] : intervals) {

            if (start > prevEnd) {

                ans.push_back(s.substr(start, end - start + 1));

                prevEnd = end;
            }
        }

        return ans;
    }
};
