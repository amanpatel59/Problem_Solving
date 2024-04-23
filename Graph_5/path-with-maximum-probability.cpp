class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
     vector<double>& succProb, int start_node, int end_node) {
        
        // THINK ABOUT IT , FEELS LIKE DIJKASTRA BUT NEED TO FIND MAXIMUM HERE

        vector<vector<pair<double,double>>>adj(n);

        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double>dist(n,-1);

        priority_queue<tuple<double,double>>maxh;
        dist[start_node] = 1.0;

        // {probab,node}
        maxh.push({1.0,start_node});
        while(!maxh.empty()){
            auto [curr_probab , node] = maxh.top();
            maxh.pop();

            if(node == end_node)return curr_probab;
            for(auto adjNode : adj[node]){
                double probab_add = adjNode.second , reaching = adjNode.first;
                if((probab_add*curr_probab) > dist[reaching]){
                    dist[reaching] = probab_add*curr_probab;
                    maxh.push({dist[reaching],reaching});
                }
            }
        }

        return dist[end_node] == -1 ? 0 : dist[end_node];
    }
};