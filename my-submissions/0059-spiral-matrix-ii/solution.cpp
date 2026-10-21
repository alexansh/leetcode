
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++)
                a[top][j] = num++;
            top++;

            for (int i = top; i <= bottom; i++)
                a[i][right] = num++;
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    a[bottom][j] = num++;
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    a[i][left] = num++;
                left++;
            }
        }

        return a;
    }
};

