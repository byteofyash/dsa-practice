// Last updated: 9/8/2026, 1:58:41 AM
auto init = [](){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}();

typedef vector<int> vecin;

class Solution {
            vector<vecin> adj;
vecin visited;
vector<vecin> bridges;

int dfs(int u, int parent){
visited[u] = 1;
int crossing_edges = 0;
for(auto& v : adj[u]){
    if(v==parent) continue;
    if(visited[v]==1) crossing_edges++;
    else if ( visited[v]==2) {
        crossing_edges--;
    }
    else{
        //visited[v] == -1
        int child_crossings  = dfs(v,u);

        if(child_crossings==0){
            bridges.push_back({u,v});
        }

                crossing_edges += child_crossings;

    }
}
visited[u]=2;
return crossing_edges;

}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& cnection) {
        adj.assign(n, {});
        visited.assign(n,-1);

        for(auto& edge: cnection ){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0 ; i< n;i++){
            if(visited[i]==-1){
                dfs(i,-1);
            }
        }

        return bridges;


    }
};