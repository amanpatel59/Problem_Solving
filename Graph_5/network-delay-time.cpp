class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i = 0 ; i < times.size() ; i++)
            adj[times[i][0]].push_back({times[i][1],times[i][2]});

        
        vector<int>time_taken(n+1,INT_MAX);
        priority_queue<tuple<int,int>>maxh;
        maxh.push({0,k});
        time_taken[0] = 0;
        time_taken[k] = 0;

        while(!maxh.empty())
        {
            auto [curr_duration , coming_from] = maxh.top();
            maxh.pop();

            for(auto i : adj[coming_from])
            {
                int destination = i.first , need = i.second;
                if(need+(-curr_duration) < time_taken[destination])
                {
                    time_taken[destination] = need+(-curr_duration);
                    maxh.push({-time_taken[destination],destination});
                }
            }
        }
        for(auto i : time_taken)if(i == INT_MAX)return -1;

        return *max_element(time_taken.begin(),time_taken.end());

    }
};