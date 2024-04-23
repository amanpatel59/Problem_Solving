class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0 ; i < flights.size() ; i++)
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});

        queue<tuple<int,int,int>>q;
        vector<int>cost(n,INT_MAX);
        // {number_of_stops , city , cost};
        q.push({0,src,0});
        cost[src] = 0;

        // SINCE OUR PRIMARY NEED IS NOT THE MINIMUM COST
        // WE PRIMARILY NEED ALTMOST K STOPS , THEN WE NEED CHEAPEST
        // i.e. WE NEED CHEAPEST FLIGHT GIVEN THAT THEIR ARE ATMOST "K" STOPS
        // THEREFORE WE'LL FOCUS ON "NUMBER OF STOPS"
        // AND SINCE INCREASE IN NUMBER OF STOPS IS CONSTANT WE'LL USE QUEUE INSTEAD OF A PRIORITY QUEUE

        while(!q.empty())
        {
            auto [stops , city , curr_cost] = q.front();
            q.pop();

            if(stops == k+1)continue;
            for(auto i : adj[city])
            {
                int to = i.first , with_cost = i.second;
                if(curr_cost+with_cost < cost[to])
                {
                    cost[to] = curr_cost+with_cost;
                    q.push({stops+1,to,cost[to]});
                }
            }
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};