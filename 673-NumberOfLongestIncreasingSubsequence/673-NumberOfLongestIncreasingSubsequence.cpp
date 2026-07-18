// Last updated: 7/18/2026, 2:25:54 PM
class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[i] == dp[j] + 1){
                        count[i]+=count[j];
                    }
                }
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }

        int ans = 0;
        for(int i =0 ; i<n;i++){
            if(dp[i]==maxLen){
                ans += count[i];
            }
        }
        return ans;

        
    }
};