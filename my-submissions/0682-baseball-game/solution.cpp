class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;

        for (string op : operations) {

            if (op == "+") {
                int a = score.top(); score.pop();
                int b = score.top();
                score.push(a);
                score.push(a + b);
            }
            else if (op == "D") {
                score.push(score.top() * 2);
            }
            else if (op == "C") {
                score.pop();
            }
            else {
                score.push(stoi(op));
            }
        }

        int sum = 0;
        while (!score.empty()) {
            sum += score.top();
            score.pop();
        }

        return sum;
    }
};
