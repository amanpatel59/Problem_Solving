class Solution {
public:
    void dfsTraversal(int node , vector<int>& vis , vector<vector<int>>& isConnected)
    {
        vis[node] = 1;
        
        for(int i = 0 ; i < isConnected[node].size() ; i++)
        {
            if(!vis[i] and isConnected[node][i])
            {
                vis[i] = 1;
                dfsTraversal(i,vis,isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int>vis(isConnected.size(),0);

        for(int i = 0 ; i < vis.size() ; i++)
        {
            if(!vis[i])
            {
                count++;
                dfsTraversal(i,vis,isConnected);
            }
        }
        return count;
    }
};