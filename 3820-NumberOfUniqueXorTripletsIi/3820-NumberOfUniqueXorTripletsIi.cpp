// Last updated: 7/31/2026, 11:16:39 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int val : nums) {
            auto next = dp;  // option: don't use this index

            for (int taken = 0; taken <= 3; taken++) {
                for (int xr = 0; xr < MAXX; xr++) {
                    if (!dp[taken][xr]) continue;

                    int left = 3 - taken;
                    for (int cnt = 1; cnt <= left; cnt++) {
                        int newXor = xr ^ ((cnt & 1) ? val : 0);
                        next[taken + cnt][newXor] = true;
                    }
                }
            }

            dp = move(next);
        }

        int ans = 0;
        for (bool ok : dp[3]) {
            if (ok) ans++;
        }

        return ans;
    }
};