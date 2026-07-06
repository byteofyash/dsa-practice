// Last updated: 7/7/2026, 2:39:39 AM
class Solution {
    private:
    bool dfs(int node,int col, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = col;
        for(auto it : adj[node]){
            if(color[it]==-1){ 
                if(dfs(it,!col, adj,color)==false) return false;
                }
            else if(color[it]== col) return false;
        }
        return true;
        
    }


public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
         // adj matrix to adj list
        vector<vector<int>> adj = graph;
        


        // dfs calls and province counting

        int count = 0;
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if(dfs(i,0, adj, color)==false) return false;
            }
        }

        return true;


    }
};