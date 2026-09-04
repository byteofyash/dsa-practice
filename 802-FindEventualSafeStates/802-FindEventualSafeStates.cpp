// Last updated: 9/4/2026, 4:59:07 PM
class Solution {
    vector<int> ans;
    vector<int> visited;
    vector<vector<int>> adj;


bool dfs (int u ){
    if(visited[u]==1) return false;
    if(visited[u]==2) return true;
    visited[u]=1;
    for(auto& v : adj[u] ){
        if(visited[v]==-1){
            if(!dfs(v)) return false;
        }
        else if(visited[v]==1){
            return false;
        }
    }
    visited[u]=2;
    return true;
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        adj = graph;
        visited = vector<int>(V,-1);
        for(int i  = 0 ; i < V;i++){
            if(dfs(i)) ans.push_back(i);
        }
        return ans;

    }
};