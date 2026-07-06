// Last updated: 7/7/2026, 2:39:27 AM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int countFresh = 0;

        // traverse and mark
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1)
                    countFresh++;
            }
        }

        int tm = 0, count = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // apply BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
                        tm = max(tm, t);


            // traversing 4 directionally adjacent
            for(int i = 0 ; i <4;i++){
                int nrow = r + delRow[i];
                int ncol =  c + delCol[i];

                //apply check
                if(nrow>=0 && nrow < m && ncol>=0 && ncol <n && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                    count++;
                }
            }
        }

        return (count==countFresh)? tm: -1;
    }
};