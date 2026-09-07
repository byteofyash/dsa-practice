// Last updated: 9/8/2026, 2:00:24 AM
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
typedef vector<int> vecin;

class DSU {
public:
    vecin parent;
    vecin size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void doUnion(int x, int z) {
        int rootX = find(x);
        int rootZ = find(z);
        if (rootX == rootZ)
            return;
        parent[rootX] = rootZ;
        size[rootZ] += size[rootX];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU obj(n * n);
        int dirs[] = {-1, 0, 1, 0, -1};

        forn(i, n) {
            forn(j, n) {
                if (grid[i][j] == 1) {
                    int u = i * n + j;
                    // check neighbours and do union
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dirs[k];
                        int nc = j + dirs[k + 1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                            if (grid[nr][nc] == 1) {
                                int v = nr * n + nc;
                                obj.doUnion(u, v);
                            }
                        }
                    }
                }
            }
        }

        bool hasZero = false;
        int maxIsland = 0 ;
        forn(i, n) {
            forn(j, n) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    unordered_set<int> uniqueRoot;
                    int currentSize = 1;

                    // check neighbours and do union
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dirs[k];
                        int nc = j + dirs[k + 1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                            if (grid[nr][nc] == 1) {
                                int v = nr * n + nc;
                                int root = obj.find(v);
                                uniqueRoot.insert(root);
                            }
                        }
                    }

                    for(auto& root : uniqueRoot){
                        currentSize += obj.size[root];
                    }

                    maxIsland = max(maxIsland, currentSize);
                }
            }
        }

        if(hasZero==false) return n*n;
        return maxIsland;




    }
};