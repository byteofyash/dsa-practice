// Last updated: 7/17/2026, 6:00:19 PM
class Solution {
    int n;
    int solve(int day, int canBuy, int transactionsLeft, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (day == n || transactionsLeft == 0)
            return 0;

        if (dp[day][canBuy][transactionsLeft] != -1)
            return dp[day][canBuy][transactionsLeft];

        int ans;

        if (canBuy) {
            // buy
            int buy =
                -prices[day] + solve(day + 1, 0, transactionsLeft, prices, dp);
            // skip
            int skip = solve(day + 1, 1, transactionsLeft, prices, dp);
            ans = max(buy, skip);
        }

        else {

            // sell
            int sell = prices[day] +
                       solve(day + 1, 1, transactionsLeft - 1, prices, dp);
            // skip
            int skip = solve(day + 1, 0, transactionsLeft, prices, dp);
            ans = max(sell, skip);
        }

        dp[day][canBuy][transactionsLeft] = ans;
        return dp[day][canBuy][transactionsLeft];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};