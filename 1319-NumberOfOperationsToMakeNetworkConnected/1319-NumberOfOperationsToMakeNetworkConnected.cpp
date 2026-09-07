// Last updated: 9/8/2026, 4:06:06 AM
#define forn(i,n) for(int i = 0 ;i<n;i++)
typedef vector<int> vecin;

class Solution {
vecin parent;
    int find(int x){
        if(parent[x]==x) return x;
        
        return parent[x] = find(parent[x]);
    }

    void doUnion(int x, int z){
            int rootX =  find(x);
            int rootZ = find(z);

            if(rootX!=rootZ){
                parent[rootX] = rootZ;
            }
    }
public:
    int makeConnected(int n, vector<vector<int>>& cnection) {

        parent.assign(n, {});
        forn(i,n){
            parent[i] = i;
        }

        if(cnection.size() < n -1) return -1;

        int components = n;
        for(auto& edge: cnection){
            int x = edge[0];
            int z = edge[1];

            int rootX =  find(x);
            int rootZ = find(z);

            if(rootX!=rootZ){
                doUnion( x, z);
                components--;
            }
        }

        return components-1;
    }
};