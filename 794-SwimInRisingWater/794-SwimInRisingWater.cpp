// Last updated: 7/16/2026, 3:10:53 AM
class Solution {

    

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto [t,r,c] = pq.top();
            pq.pop();
            // int t = top.first;
            // int r = top.second;
            // int c = top.third;
            if (t > dist[r][c])
                continue;
            if(r==n-1 && c==n-1) return t;


            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newTime = max(t, grid[nr][nc]);
                    if (newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, nr, nc});
                    }
                }
            }
        }
        

        return dist[n-1][n-1];
    }
};