class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n),ans(n);

        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1];
            // reversing every edge
            adjList[v].push_back(u);
        }
        
        for(int i = 0 ; i < n ; i++){
            vector<int>vis(n,0);
            vis[i] = 1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                auto currNode = q.front();
                vis[currNode] = 1;
                q.pop();
                for(auto adjNode : adjList[currNode]){
                    if(!vis[adjNode]){
                        ans[i].push_back(adjNode);
                        q.push(adjNode);
                        vis[adjNode] = 1;
                    }
                }
            }
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};