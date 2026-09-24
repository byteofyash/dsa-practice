// Last updated: 9/24/2026, 5:37:24 AM
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
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        FOR(i, 1, m) {
            FOR(j, 1, n) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = m, j = n;
        string res = "";
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                res += str1[i-1];
                --i; --j;
            } else if(dp[i-1][j]> dp[i][j-1]) {
                res+= str1[i-1];
                --i;
            }
            else{
                res += str2[j-1];
                --j;
            }
        }

         while (i > 0) {
            res.push_back(str1[i - 1]);
            --i;
        }

        while (j > 0) {
            res.push_back(str2[j - 1]);
            --j;
        }

        reverse(all(res));
        return res;
    }
};