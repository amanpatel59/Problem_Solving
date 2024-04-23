class Solution {
public:
    bool bfs(int node , vector<int>&color , vector<vector<int>>&graph)
    {
        queue<pair<int,int>>q;
        q.push({node,0});
        while(!q.empty())
        {
            int curr_node = q.front().first , curr_color = q.front().second;
            q.pop();
            for(auto i : graph[curr_node])
            {
                if(color[i] == -1)
                {
                    color[i] = !curr_color;
                    q.push({i,!curr_color});
                }
                else if(color[i] == curr_color)return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i = 0 ; i < color.size() ; i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                if(!bfs(i,color,graph))return false;;
            }
        }
        return true;
    }
};