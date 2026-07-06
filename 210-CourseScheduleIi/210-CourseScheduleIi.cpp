// Last updated: 7/7/2026, 2:41:10 AM
class Solution {

private:
    bool checkCycle(int node, vector<int>& vis, vector<int>& dfsVis,
                    stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto it : adj[node]) {
            if (vis[it] != 1) {
                if (checkCycle(it, vis, dfsVis,st ,adj))
                    return true;
            } else if (dfsVis[it] == 1)
                return true;
        }

        dfsVis[node] = 0;
        st.push(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        bool canFinish = true;

        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] != 1) {
                if (checkCycle(i, vis, dfsVis,st, adj)) {
                    canFinish = false;
                    break;
                }
            }
        }

        vector<int> ans;

        if (canFinish) {
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};