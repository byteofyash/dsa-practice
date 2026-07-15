// Last updated: 7/15/2026, 6:19:02 PM
class Solution {

    int orgcolor;
    int m, n;
    void dfs(int row, int col, vector<vector<int>>& image, int color) {
        image[row][col] = color;
        int dr[] = {-1,1,0,0};
        int dc[]= {0,0,-1,1};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                if (image[nr][nc] == orgcolor) {
                    dfs(nr, nc, image, color);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        m = image.size();
        n = image[0].size();
        
        orgcolor = image[sr][sc];
        if (orgcolor == color)
            return image;

        image[sr][sc] = color;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == orgcolor) {
                    dfs(sr, sc, image, color);
                }
            }
        }
        return image;
    }
};