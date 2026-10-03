// Last updated: 10/3/2026, 6:50:25 PM
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
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pii> line;
        for(auto& x : logs){
            int l = x[0];
            line.pb({l,1});

            int r  = x[1];
            line.pb({r,-1});
        }

        sort(all(line));

        int curr = 0, maxPop = 0, minYr = 0 ;
        for(auto& x : line){
                curr+= x.second;
                if(curr> maxPop){
                        maxPop  =  curr;
                        minYr = x.first;
                }
                
        }

        return minYr;
    }
};