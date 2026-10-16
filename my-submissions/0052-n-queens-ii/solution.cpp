
class Solution {
public:
    int ans = 0;

    void solve(int row, int n, vector<bool>& col,
               vector<bool>& d1, vector<bool>& d2) {
        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || d1[row - c + n - 1]
                || d2[row + c])
                continue;

            col[c] = d1[row - c + n - 1] = d2[row + c] = true;

            solve(row + 1, n, col, d1, d2);

            col[c] = d1[row - c + n - 1] = d2[row + c] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> d1(2 * n - 1, false);
        vector<bool> d2(2 * n - 1, false);

        solve(0, n, col, d1, d2);
        return ans;
    }
};

