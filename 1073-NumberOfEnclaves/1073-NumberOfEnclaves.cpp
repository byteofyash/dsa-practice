// Last updated: 7/15/2026, 6:18:45 PM
class Solution {
    int m, n;
    void dfs(int row, int col, vector<vector<int>>& board) {
        board[row][col] = 7;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                if (board[nr][nc] == 1) {
                    dfs(nr, nc, board);
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        // top column
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 1) {
                dfs(0, j, board);
            }
        }

        // bottom col
        for (int j = 0; j < n; j++) {
            if (board[m - 1][j] == 1) {
                dfs(m - 1, j, board);
            }
        }

        // left column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 1) {
                dfs(i, 0, board);
            }
        }

        // right column
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 1) {
                dfs(i, n - 1, board);
            }
        }
        int count = 0 ; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    count++;
                    board[i][j] = 3;
                } 
                else if (board[i][j] == 7) {
                    board[i][j] = 1;
                }
            }
        }
        return count;
    }
};