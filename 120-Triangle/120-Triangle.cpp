// Last updated: 7/17/2026, 6:09:12 PM
class Solution {
    int solve(int i, int j, vector<vector<int>>& dp,
              vector<vector<int>>& grid) {

        if (i < 0 || j < 0)
            return 1e9;
        if (j>i)
            return 1e9;

        if (i == 0 && j == 0)
            return grid[0][0];

        if (dp[i][j] != (-1))
            return dp[i][j];

        dp[i][j] = grid[i][j] + min(solve(i - 1, j, dp, grid), solve(i-1, j -1, dp, grid));
        return dp[i][j];
    }

public:
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int mini = 1e9;
        for(int i = 0 ;i <n; i++){
            mini = min(mini, solve(m - 1, i, dp, grid) );
        }  
        return mini;
    }
};