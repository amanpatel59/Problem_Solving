class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adjList(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            auto currNode = q.front();
            if(currNode == destination)return true;
            q.pop();
            for(auto adjNode : adjList[currNode]){
                if(!vis[adjNode]){
                    q.push(adjNode);
                    vis[adjNode] = 1;
                }
            }
        }
        return false;
    }
};