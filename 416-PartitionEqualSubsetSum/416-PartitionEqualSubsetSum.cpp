// Last updated: 9/19/2026, 1:53:25 PM
#include <bits/stdc++.h>
using namespace std;

// Execute fast I/O before LeetCode's driver runs
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// Macros & Shortcuts
#define ln '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define rforn(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

// Type Aliases
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vecin;
typedef vector<ll> vecll;
typedef vector<pii> vecpii;
typedef set<int> setin;
typedef set<ll> setll;

// Constants
const int INF = 1e9;
const int MOD = 1e9 + 7;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(all(nums),0);
        if(totalSum %2 !=0 ) return false;
        int sum = totalSum/2;

        //------//

        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(auto& x : nums){
            for(int i = sum; i >= x;i--){
                    dp[i] = dp[i] + dp[i-x];
            }
        }
        return dp[sum];
    }
};