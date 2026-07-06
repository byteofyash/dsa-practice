// Last updated: 7/7/2026, 2:41:27 AM
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        //base case
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0'; // sink the current land/mark this position as visited

        // run dfs on all the neighbours to mark the extent of land
        dfs(grid, r, c + 1);
        dfs(grid, r+1, c);
        dfs(grid, r, c-1);
        dfs(grid, r-1, c);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islandCount = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j); // find connected land
                }
            }
        }
        return islandCount;
    }
};