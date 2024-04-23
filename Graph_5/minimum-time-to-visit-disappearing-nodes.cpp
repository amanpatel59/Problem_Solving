class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>adjList(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] ,wt = edges[i][2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        
        vector<int>dist(n,INT_MAX),vis(n,0);
        dist[0] = 0;
        vis[0] = 1;
        set<pair<int,int>>st;
        st.insert({0,0});
        
        while(!st.empty()){
            auto it = *st.begin();
            int currDist = it.second , currNode = it.first;
            st.erase(it);
            for(auto adjNode : adjList[currNode]){
                int node = adjNode.first , newDist = adjNode.second;
                if(newDist+currDist >= disappear[node])continue;
                if(dist[node] > newDist+currDist){
                    pair<int,int>toRemove = {node,dist[node]};
                    st.erase(toRemove);
                    dist[node] = newDist+currDist;
                    st.insert({node,dist[node]});
                }
            }
        }
        
        for(auto& i : dist)if(i == INT_MAX)i=-1;
        
        return dist;
    }
};