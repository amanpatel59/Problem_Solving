class Solution {
public:
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     // now since we are considering every node as a starting node at some point 
    //     // this can be solved using multisource shortest path algo
    //     // FLOYD WARSHAL

    //     vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
    //     for(int i = 0 ; i < n ; i++)cost[i][i] = 0;

    //     for(auto edge : edges){
    //         cost[edge[0]][edge[1]] = edge[2];
    //         cost[edge[1]][edge[0]] = edge[2];
    //     }

    //     for(int via = 0 ; via < n ; via++){
    //         for(int from = 0 ; from < n ; from++){
    //             for(int to = 0 ; to < n ; to++){
    //                 if(cost[from][via] == INT_MAX or cost[via][to] == INT_MAX)continue;
    //                 cost[from][to] = min(cost[from][to] , (cost[from][via]+cost[via][to]));
    //             }
    //         }
    //     }

    //     int mini = INT_MAX , ans = 0;

    //     for(int i = 0 ; i < n ; i++){
    //         int count = 0;
    //         for(int j = 0 ; j < n ; j++){
    //             if(cost[i][j] <= distanceThreshold and i!=j)count++;
    //         }
    //         if(count <= mini){
    //             ans = i;
    //             mini = count;
    //         }
    //     }
    //     return ans;
    // }


    // NOW SINCE THEIR ARE NO -VES HENCE WE CAN ALSO APPLY DIJKASTRA FOR EACHH NODE
    // THIS WILL BE BETTER IN TERMS OF TIME COMPLEXITY

    void dijkstra(int source , int n , vector<vector<pair<int,int>>>&adj , vector<int>&dist){
        dist[source] = 0;
        priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>>minh;
        minh.push({0,source});

        while(!minh.empty()){
            auto [curr_wt , node] = minh.top();
            minh.pop();
            for(auto i : adj[node]){
                int ewt = i.second , dst = i.first;

                if(ewt+curr_wt < dist[dst]){
                    dist[dst] = ewt+curr_wt;
                    minh.push({dist[dst],dst});
                }
            }
        }
        return ;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int mini = INT_MAX , ans = 0;
        for(int i = 0 ; i < n ; i++){
            vector<int>dist(n,1e9);
            int count = 0;
            dijkstra(i , n , adj , dist);
            for(auto it : dist){if(it <= distanceThreshold and it != 0){count++;}}
            if(count <= mini){
                mini = count;
                ans = i;
            }
        }
        return ans;
    }
};