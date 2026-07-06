// Last updated: 7/7/2026, 2:38:53 AM
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();

        int dirs[4][2] = {{0,1}, {1,0},{-1,0},{0,-1}} ;

        vector<vector<int>> dist(rows,vector<int>(cols,1e9));
        dist[0][0] = grid[0][0];
        deque<pair<int,int>> dq;
        dq.push_front({0,0});



        while(!dq.empty()){
            auto [r,c] = dq.front();
            dq.pop_front();

            if(r==rows-1 && c == cols -1 ) break;

            for(auto& d : dirs){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr>=0 && nc >=0 && nr < rows && nc < cols){
                    int damage = grid[nr][nc];

                    if(dist[r][c]+ damage < dist[nr][nc]){
                        dist[nr][nc]= dist[r][c]+ damage;

                        if(damage ==0 ) {
                            dq.push_front({nr,nc});
                        }
                        else  dq.push_back({nr,nc});
                    }
                }
            }
        }

        return (health - dist[rows-1][cols-1]) >=1;
        
    }
};