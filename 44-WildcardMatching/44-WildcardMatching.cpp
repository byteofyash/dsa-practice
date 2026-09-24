// Last updated: 9/24/2026, 5:41:41 AM
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
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
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
    bool isMatch(string s, string p) {
        int m = sz(s);
        int n = sz(p);

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        FOR(j,1,n){
            if(p[j-1]=='*') dp[0][j] = dp[0][j-1];
            else break;
        }
     

            FOR(i, 1, m) {
                FOR(j, 1, n) {
                    if (s[i - 1] == p[j - 1]|| p[j-1]=='?') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else{
                        if( p[j-1]=='*'){
                            dp[i][j] = dp[i][j - 1] || dp[i-1][j];
                        }
                    }
                }
            }

            return dp[m][n]; 
    }
};