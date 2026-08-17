class Solution {
public:
    vector<int> solve(string s) {

        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {

                string left = s.substr(0, i);
                string right = s.substr(i + 1);

                vector<int> leftResults = solve(left);
                vector<int> rightResults = solve(right);

                for (int a : leftResults) {
                    for (int b : rightResults) {

                        if (s[i] == '+')
                            ans.push_back(a + b);

                        else if (s[i] == '-')
                            ans.push_back(a - b);

                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If there is no operator, s is just a number
        if (ans.empty())
            ans.push_back(stoi(s));

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
