// Last updated: 9/4/2026, 4:58:00 PM
class Solution {

struct Node{
    int row;
    int col;
    int time;
};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int dr[] = {-1,1, 0 , 0 };
        int dc[] = {0,0,-1,1};


        queue<Node> q;
        int freshCount  = 0;

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j< n;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
                if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }
        while(!q.empty()){
            auto front = q.front(); q.pop();
            int row = front.row;
            int col = front.col;
            int time = front.time;
            ans = time;

            for(int i = 0 ; i < 4;i++)
            {
                int nr = row + dr[i];
                int nc = col+ dc[i]; 
                if(nr<m && nc < n && nr >=0 && nc>=0 && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    freshCount--;
                    q.push({nr,nc,time+1});
                }
            }

        }
        if(freshCount==0) return ans;
        else return -1;

        
    }
};