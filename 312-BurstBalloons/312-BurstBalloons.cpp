// Last updated: 9/24/2026, 5:39:17 AM
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
    int memo[305][305];
    int solve(int i , int j , vector<int>& arr){
        if(i+1>=j) return 0;


        if(memo[i][j]!=-1)return memo[i][j];

        int maxCoins =0 ; 
        for(int k = i +1; k<=j-1;k++){
            int coins = solve(i,k,arr) + solve(k,j,arr) + (arr[i] * arr[k] * arr[j]);
            maxCoins = max(maxCoins, coins);
        }

        return memo[i][j] = maxCoins;


    }
public:
    int maxCoins(vector<int>& nums) {


        int n= nums.size();

        vecin arr = {1};
        arr.insert(arr.end(), all(nums));
        arr.pb(1);

        memset(memo, -1, sizeof(memo));
        return solve(0, n+1, arr);

    }
};