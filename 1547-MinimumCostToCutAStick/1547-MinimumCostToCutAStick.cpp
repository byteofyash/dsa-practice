// Last updated: 9/24/2026, 5:36:47 AM
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
    int memo[105][105];

    int solve (int i , int j , vector<int>& cuts){
            if(i+1>=j) return 0;
            if(memo[i][j]!=-1) return memo[i][j];

            int minCost = 1e9;
            for(int k = i+1; k<=j-1;k++){
                int cost = solve(i,k, cuts) + solve(k,j, cuts) + (cuts[j]-cuts[i]);
                minCost = min(cost, minCost);
            }

            return memo[i][j] = minCost;

    }
public:
    int minCost(int n, vector<int>& cuts) {
      
        cuts.pb(0);
        cuts.pb(n);
        sort(all(cuts));
  int c = sz(cuts);
        memset( memo,-1, sizeof(memo));

        return solve(0,c-1, cuts);

    }
};