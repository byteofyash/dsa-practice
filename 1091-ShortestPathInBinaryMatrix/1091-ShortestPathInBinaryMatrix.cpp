// Last updated: 9/4/2026, 4:57:08 PM
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
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vecin;
typedef vector<ll> vecll;
typedef set<int> setin;
typedef set<ll> setll;

// Constants
const int INF = 1e9;
const int MOD = 1e9 + 7;

class Solution {
    vector<vecin> visited;

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        visited.assign(n, vector<int>(n,-1));

        // edge cases
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // 8 dir arr
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pii> q;
        q.push({0, 0});
        visited[0][0] = 1;
        int dist = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                if (r == n - 1 && c == n - 1)
                    return dist;

                for (int i = 0; i < 8; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                        visited[nr][nc] == -1) {
                        if (grid[nr][nc] == 0) {
                            visited[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};