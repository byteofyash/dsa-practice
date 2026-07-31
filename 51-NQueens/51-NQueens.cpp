// Last updated: 7/31/2026, 11:23:44 PM
class Solution {
    int n;
    vector<vector<string>> result;
    vector<string> board;

    void recurse(int r) {
        if (r == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(r, i)) {
                board[r][i] = 'Q';
                recurse(r + 1);
                board[r][i] = '.';
            }
        }
    }

    bool isSafe(int r, int c) {

        int dr[] = {-1, -1, -1};
        int dc[] = {0, -1, 1};

        for (int i = 0; i < 3; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            while (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                if (board[nr][nc] == 'Q')
                    return false;
                nr += dr[i];
                nc += dc[i];
            }
        }
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int grid) {
        n = grid;
        board = vector<string>(n, string(n, '.'));
        recurse(0);
        return result;
    }
};