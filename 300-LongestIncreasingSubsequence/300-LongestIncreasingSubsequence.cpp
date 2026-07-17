// Last updated: 7/17/2026, 7:47:56 PM
class Solution {
int n ;
    int solve(int i, int prevIndex, vector<int>& nums, vector<vector<int>>& dp) 
    {
        if (i == n)
            return 0 ;
            
        if (dp[i][prevIndex+1] != -1) return dp[i][prevIndex+1];

        // take
        int take = 0;
        if (prevIndex == -1 || nums[i] > nums[prevIndex])
             take = 1 + solve(i + 1, i, nums, dp);

        // skip
         int skip = solve(i + 1, prevIndex, nums,dp);

        return dp[i][prevIndex+1] = max(take, skip);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
         n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
         return solve(0, -1, nums,dp);
    }
};