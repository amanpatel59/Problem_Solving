class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adjList(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j)continue;
                int cost = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adjList[i].push_back({j,cost});
                adjList[j].push_back({i,cost});
            }
        }

        int ans = 0;
        vector<int>vis(n,0);
        priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>>pq;
        pq.push({0, 0}); // {cost, node}

        while (!pq.empty()) {
            auto [currCost, currNode] = pq.top();
            pq.pop();

            if (vis[currNode]) continue;

            ans += currCost;
            vis[currNode] = 1;

            for (auto [adjNode, adjCost] : adjList[currNode]) {
                if(!vis[adjNode])pq.push({adjCost, adjNode});
            }
        }

        return ans;
    }
};