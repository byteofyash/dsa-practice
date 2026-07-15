// Last updated: 7/15/2026, 6:19:07 PM
class Solution {

struct Node{
    int row;
    int col;
    int distance;
};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distMat(m, vector<int>(n,0));
        int ans = 0;
        int dr[] = {-1,1, 0 , 0 };
        int dc[] = {0,0,-1,1};

        queue<Node> q;
        vector<vector<int>> visited(m, vector<int>(n,-1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    visited[i][j]=1;
                    q.push({i, j, 0});
                }
                
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int row = front.row;
            int col = front.col;
            int dist = front.distance;
            distMat[row][col] = dist;  
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr < m && nc < n && nr >= 0 && nc >= 0 &&
                    grid[nr][nc] == 1 && visited[nr][nc]==-1) {
                        visited[nr][nc]=1;
                    q.push({nr, nc, dist + 1});
                }
            }
        }
                    return distMat;


    }
};