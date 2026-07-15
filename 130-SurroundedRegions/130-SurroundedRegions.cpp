// Last updated: 7/15/2026, 11:50:31 PM
class Solution {
    int m , n;
void dfs(int row, int col, vector<vector<char>>& board){
    board[row][col] = 'S';
        int dr[] = {-1,1,0,0};
        int dc[]= {0,0,-1,1};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                if (board[nr][nc] == 'O') {
                    dfs(nr, nc, board);
                }
            }
        }

}
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        //top column
        for(int j = 0 ; j < n;j++){
            if(board[0][j]=='O'){
                dfs(0,j, board);
            }
        }

        //bottom col
        for(int j = 0 ; j < n;j++){
            if(board[m-1][j]=='O'){
                dfs(m-1,j, board);
            }
        }

        //left column
        for(int i = 0 ; i < m;i++){
            if(board[i][0]=='O'){
                dfs(i,0, board);
            }
        }

        //right column
        for(int i = 0 ; i < m;i++){
            if(board[i][n-1]=='O'){
                dfs(i,n-1, board);
            }
        }




        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                   board[i][j] = 'X';
                }
                else if(board[i][j] == 'S') {
                   board[i][j] = 'O';
                }
            }
        }


        

    }
};