// Last updated: 7/15/2026, 11:49:28 PM
class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);

        if (u == v)
            return false;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        DSU dsu(n);
        int components = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    if (dsu.unionBySize(i, j))
                        components--;
                }
            }
        }

        return n - components;
    }
};