// Last updated: 7/9/2026, 6:05:51 PM
class Solution {
    bool recurse(int i, vector<int>& dp, string& s, vector<string>& wordDict) {
        if (i == s.size())
            return true;
        if(dp[i]!=-1) return dp[i];

        for (auto& x : wordDict) {
            if (s.substr(i, x.length()) == x) {
                if(recurse(i + x.length(),dp, s, wordDict)) {dp[i]=1;return true;}
            }
        }
        dp[i]=0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n,-1);
       return recurse(0,dp, s, wordDict);
    }
};