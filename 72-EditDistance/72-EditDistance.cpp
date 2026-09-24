// Last updated: 9/24/2026, 5:41:18 AM
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
    int minDistance(string word1, string word2) {
        int m = sz(word1);
        int n = sz(word2);

        vector<vector<int>> dp(m+1, vecin(n+1, 0));

        //base cases
        FOR(i,1,m){
 dp[i][0]=i;
        }

        FOR(j,1,n){
 dp[0][j]=j;
        }



        FOR(i,1,m){
           
            FOR(j,1,n){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] =  dp[i-1][j-1];
                }
                else{
                 dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
            }
        }

        return dp[m][n];
    }
};