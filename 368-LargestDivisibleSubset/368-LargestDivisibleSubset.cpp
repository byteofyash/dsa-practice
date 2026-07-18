// Last updated: 7/18/2026, 2:26:06 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        int maxi = 0;
        int lastIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(arr[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};