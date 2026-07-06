// Last updated: 7/7/2026, 2:38:55 AM
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;
        // thief already present at the start and at the end
        // so minimum distance will always be 0

        queue<pair<int, int>> q;

        // now apply multi source bfs to calculate distance of each empty cell
        // from thief cell
        //  push all thieves into queue

        vector<vector<int>> dist(n, vector<int>(n, -1));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (q.empty() == false) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

            // now use max heap with djikstra
            // to maximum min_safe score

            priority_queue<tuple<int, int, int>> pq;
            vector<vector<bool>> visited(n, vector<bool>(n, false));

            pq.push({dist[0][0], 0, 0});
            visited[0][0] = true;

            while (pq.empty() == false) {
                auto [safe, r, c] = pq.top();

                pq.pop();

                if (r == n - 1 && c == n - 1)
                    return safe;

                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                        visited[nr][nc] == false) {
                        visited[nr][nc] = true;
                        int min_safe = min(safe, dist[nr][nc]);
                        pq.push({min_safe, nr, nc});
                    }
                }
            }
            return 0;
        }
    
};