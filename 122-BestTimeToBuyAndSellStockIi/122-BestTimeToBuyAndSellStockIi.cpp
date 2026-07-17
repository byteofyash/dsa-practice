// Last updated: 7/17/2026, 6:09:10 PM
class Solution {
    int n;
    int solve(int day, int canBuy, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (day == n)
            return 0;

        if (dp[day][canBuy] != -1)
            return dp[day][canBuy];
        
        int ans;

        if (canBuy) {
            // buy
            int buy = -prices[day] + solve(day + 1, 0, prices, dp);
            // skip
            int skip = solve(day + 1, 1, prices, dp);
            ans = max(buy, skip);
        }

        else {
            // sell
            int sell = prices[day] + solve(day + 1, 1, prices, dp);
            // skip
            int skip = solve(day + 1, 0, prices, dp);
            ans = max(sell, skip);
        }

        dp[day][canBuy] = ans;
        return dp[day][canBuy];
    }

public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};