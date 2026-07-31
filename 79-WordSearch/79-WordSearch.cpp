// Last updated: 7/31/2026, 11:23:04 PM
class Solution {
    int m, n, l;

    bool dfs(int r, int c, int k, string& word, vector<vector<char>>& board) {
        if (k == l)
            return true;

        if (r >= m || c >= n || r<0 || c <0)
            return false;
        if (board[r][c] == '#')
            return false;
        if (board[r][c] != word[k])
            return false;

        char org = board[r][c];
        board[r][c] = '#';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (dfs(nr, nc, k + 1, word, board) == true) {
                board[r][c]= org;
                return true;
            }
        }
        board[r][c] = org;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, word, board))
                    return true;
            }
        }
        return false;
    }
};