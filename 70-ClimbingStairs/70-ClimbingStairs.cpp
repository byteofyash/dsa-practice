// Last updated: 7/16/2026, 1:33:02 PM
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int dp[n+1];
        dp[1] = 1;
        dp[2]=2;
        if(n==1 || n==2) return dp[n];

        for(int i =3;i<=n;i++){
            dp[i]= dp[i-1]+ dp[i-2];
        }
        return dp[n];
        
    }
};