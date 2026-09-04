// Last updated: 9/4/2026, 4:55:07 PM
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();


        int dirs[] = {-1,0,1,0,-1};

        vector<vecin> effort;
        effort.assign(row,vecin(col,INT_MAX));
        effort[0][0] = 0;

        using Node = tuple<int,int,int>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        // effort, row, col

        pq.push({0,0,0});

        while(!pq.empty()){
            auto [currEffort, r, c] = pq.top(); pq.pop();
            if(currEffort > effort[r][c]) continue;
            if(r==row-1 && c== col-1) {
                return effort[r][c];
            }

            for(int i  = 0 ; i< 4;i++){
                int nr = r + dirs[i];
                int nc  = c + dirs[i+1];

                if(nr >=0 && nc >=0 && nr < row && nc < col){
                    int jump = abs(heights[nr][nc]-heights[r][c]);
                    int newEffort = max(currEffort, jump);
                    if(newEffort < effort[nr][nc]){
                        effort[nr][nc] = newEffort;
                        pq.push({effort[nr][nc], nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};