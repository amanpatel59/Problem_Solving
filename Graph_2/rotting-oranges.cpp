class Solution {
public:
    int bfs(vector<vector<int>>& grid , vector<vector<int>>& vis , queue<pair<int,int>>&q , int total_fresh)
    {
        int fresh = 0 , time = 0;
        while(!q.empty())
        {
            int size = q.size();
            time++;
            // size ki jagah q.size() kr rakha tha
            for(int i = 0 ; i < size ; i++)
            {
                int curr_row = q.front().first , curr_col = q.front().second;
                q.pop();
                vis[curr_row][curr_col] = 1;
                int a[4] = {0,0,-1,1} , b[4] = {-1,1,0,0};

                for(int i = 0 ; i < 4 ; i++)
                {
                    int n_row = curr_row+a[i] , n_col = curr_col+b[i];
                    if(n_row >= 0 and n_col >= 0 and n_row < grid.size() and n_col < grid[0].size() and !vis[n_row][n_col] and grid[n_row][n_col] != 0)
                    {
                        if(grid[n_row][n_col] == 1)fresh++;
                        if(fresh == total_fresh)return time;
                        vis[n_row][n_col] = 1;
                        q.push({n_row,n_col});
                    }
                }
            }
        }
        return -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>>q;
        int total_fresh = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j <  grid[0].size() ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)total_fresh++;
            }
        }
        if(total_fresh == 0)return 0;
        return bfs(grid,vis,q,total_fresh);
    }
};