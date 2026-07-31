// Last updated: 7/31/2026, 11:24:01 PM
class Solution {
public:
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;

                int b = (i / 3) * 3 + (j / 3);

                for (int num = 1; num <= 9; num++) {
                    if (row[i][num] || col[j][num] || box[b][num])
                        continue;

                    board[i][j] = num + '0';
                    row[i][num] = col[j][num] = box[b][num] = true;

                    if (solve(board))
                        return true;

                    board[i][j] = '.';
                    row[i][num] = col[j][num] = box[b][num] = false;
                }

                return false; // no valid number fits
            }
        }

        return true; // board completely filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                int b = (i / 3) * 3 + (j / 3);

                row[i][num] = true;
                col[j][num] = true;
                box[b][num] = true;
            }
        }

        solve(board);
    }
};