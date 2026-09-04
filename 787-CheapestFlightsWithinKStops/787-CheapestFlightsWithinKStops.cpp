// Last updated: 9/4/2026, 4:59:18 PM
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
vector<vector<pii>> adj;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int V = n;
        adj.assign(n,{});
        for(auto& edge : flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].pb({v,wt});
        }

        queue<pii> q;
        vecin dist;
        dist.assign(V, INT_MAX);

        q.push({0, src});
        dist[src] = 0;

        int stops = 0 ;

        while(!q.empty() && stops<=k){
            int size = q.size();
            while(size--){
                auto [d, u] = q.front(); q.pop();

                for(auto& [v,wt] : adj[u]){
                    if(d + wt< dist[v]){
                        dist[v] = d + wt;
                        q.push({dist[v], v});
                    }
                }
            }
            stops++;
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];

    }
};