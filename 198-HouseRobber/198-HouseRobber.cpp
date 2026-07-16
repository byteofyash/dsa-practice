// Last updated: 7/16/2026, 1:32:08 PM
class Solution {
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i==0) return nums[i];
        if(i==1) return max(nums[0], nums[1]);
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MIN;
        int take = nums[i]+ solve(i-2, nums,dp);
        int notTake = solve(i-1, nums,dp);
        ans = max(take, notTake);
        dp[i] = ans;
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n-1, nums, dp);
        
    }
};