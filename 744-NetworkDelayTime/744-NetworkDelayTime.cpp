// Last updated: 7/15/2026, 11:49:38 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjlist(n+1);
        for (int i = 0; i < times.size(); i++) {
            
                int u =  times[i][0];
                int v = times[i][1];
                int w = times[i][2];
                adjlist[u].push_back({v,w});
            
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        //{currdist, node}
        pq.push({0,k});

        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int currdist = top.first;
            int node = top.second;
            if(currdist > dist[node]) continue;
            for(auto& neighbour : adjlist[node]){
                int v = neighbour.first;
                int w = neighbour.second;
                if(currdist + w < dist[v]){
                    dist[v]= currdist + w;
                    pq.push({dist[v], v});
                }
            } 
        }

        int ans = 0 ;
        for(int i =1; i<=n;i++){
                if(dist[i]==INT_MAX) return -1;
                ans = max(dist[i],ans);
        }
        
        return ans;
    }
};