// Last updated: 9/24/2026, 5:40:26 AM
class Solution {


public:
    int minCut(string s) {

        int n = s.size();
        vector<int> dp(n);

        for(int i = 0 ; i<n;i++ ){
            dp[i] = i;
        }

        for (int center = 0; center < n; center++) {

            // odd lenght palindrome ctheck
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int cuts = (l == 0) ? 0 : 1 + dp[l - 1];
                dp[r] = min(dp[r], cuts);
                l--;
                r++;
            }

            // even length
             l = center, r = center+1;
            while (l >= 0 && r < n && s[l] == s[r]) {
               int cuts = (l == 0) ? 0 : 1 + dp[l - 1];
                dp[r] = min(dp[r], cuts);
                l--; r++;
            }
        }
        return dp[n-1];
    }
};