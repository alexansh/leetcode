class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(int row, int col, vector<string>& board, int n) {

        int x = row, y = col;

        while (y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
        }

        x = row;
        y = col;

        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        x = row;
        y = col;

        while (x < n && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, int n) {

        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {

            if (isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(col + 1, board, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return ans;
    }
};
