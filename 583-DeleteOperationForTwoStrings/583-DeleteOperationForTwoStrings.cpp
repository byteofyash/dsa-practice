// Last updated: 9/24/2026, 5:38:27 AM
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
    int minDistance(string word1, string word2) {
        int m = sz(word1);
        int n = sz(word2);

        vecin prev( n+1, 0);
        vecin curr(n+1,0);

        for(int i = 1 ; i <= sz(word1);i++){
                for(int j = 1; j<=n;j++ ){

                    if(word1[i-1]==word2[j-1]){
                        curr[j] =  1 + prev[j-1];
                    }

                    else{
                        curr[j] = max( prev[j],curr[j-1]);
                    }
                }
                prev = curr;
        } 

        int lcs = prev[n];
        return m+n-2*lcs;
        
    }
};