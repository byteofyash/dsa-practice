// Last updated: 7/18/2026, 3:49:54 PM
class Solution {
    int n;
    int solve(int i, vector<int>& arr, int k, vector<int> & dp) {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi = 0, len = 0, ans = 0 ;
        for (int j = i; j <=min(n-1, i+ k-1); j++) {
            
            maxi = max(maxi, arr[j]);
            len++;
            int contribution = maxi * len;
            ans = max(ans, contribution + solve(j + 1,arr,k,dp));
        }
        return dp[i]=ans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> dp(n,-1);
        return solve(0, arr, k,dp);
    }
};