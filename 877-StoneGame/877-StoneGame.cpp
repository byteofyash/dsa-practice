// Last updated: 9/4/2026, 4:58:42 PM
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int left = 0; left + len - 1 < n; left++) {
                int right = left + len - 1;

                int takeLeft = piles[left] - dp[left + 1][right];
                int takeRight = piles[right] - dp[left][right - 1];

                dp[left][right] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n - 1] > 0;
    }
};