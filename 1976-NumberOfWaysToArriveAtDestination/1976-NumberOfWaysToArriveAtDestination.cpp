// Last updated: 9/4/2026, 4:54:10 PM
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
typedef pair<ll, int> pli;
typedef vector<int> vecin;
typedef vector<ll> vecll;
typedef vector<pii> vecpii;
typedef set<int> setin;
typedef set<ll> setll;

// Constants
const int INF = 1e9;
const int MOD = 1e9 + 7;
class Solution {
vector<vecpii> adj;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        adj.assign(n,{});
        for(auto& edge : roads){
            adj[edge[0]].pb({edge[1],edge[2]});
            adj[edge[1]].pb({edge[0],edge[2]});
        }

        vector<ll> dist(n, LLONG_MAX);
        vector<int> ways(n,0);
        priority_queue<pli, vector<pli>, greater<pli>> pq;

        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d> dist[u]) continue;

            for(auto& [v,wt] : adj[u]){

                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                }
                else if (d+ wt==dist[v]){
                    ways[v] = (ways[v]+ways[u]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};