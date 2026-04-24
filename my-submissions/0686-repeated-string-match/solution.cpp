class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int count = 1;

        while (temp.size() < b.size()) {
            temp += a;
            count++;
        }

        if (temp.find(b) != string::npos) return count;
        if ((temp + a).find(b) != string::npos) return count + 1;

        return -1;
    }
};
