// Last updated: 8/13/2026, 9:30:23 PM
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        vector<int> suspicious(n, 0);

        queue<int> q;
        q.push(k);
        suspicious[k] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = 1;
                    q.push(v);
                }
            }
        }

        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> all;
                for (int i = 0; i < n; i++)
                    all.push_back(i);
                return all;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};