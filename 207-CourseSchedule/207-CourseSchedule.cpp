// Last updated: 7/7/2026, 2:41:14 AM
class Solution {
private:
    bool checkCycle(int node, vector<int>& vis, vector<int>& dfsVis,vector<vector<int>>& adj) {
        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto it : adj[node]) {
            if (vis[it] != 1) {
                if (checkCycle(it, vis, dfsVis, adj))
                    return true;
            } else if (dfsVis[it] == 1)
                return true;
        }

        dfsVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

            for(auto it: prerequisites){
                int u = it[0];
                int v = it[1];

                adj[u].push_back(v);
            }
            
        vector<int> vis(numCourses,0);
        vector<int> dfsVis(numCourses,0);
        
        
        for(int i  =0 ; i< numCourses; i++){
            if(vis[i]!=1) {
                if(checkCycle(i, vis, dfsVis, adj)) return false;
            }
        }
        
        return true;
    }
};