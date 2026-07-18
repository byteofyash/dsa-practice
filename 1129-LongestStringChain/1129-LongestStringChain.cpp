// Last updated: 7/18/2026, 2:25:37 PM
class Solution {
    bool isPredecessor(string& small, string& large) {
        if (large.size() - small.size() != 1)
            return false;

        int i = 0;
        int j = 0;
        while (i < small.size()) {
            if (small[i] == large[j]) {
                i++;
            }
            j++;
            if(j==large.size()) break;
        }
         
         return i==small.size();

    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(),
     [](const string &a, const string &b) {
         return a.size() < b.size();
     });

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, dp[i]);
        }

        
        return maxi;
    }
};