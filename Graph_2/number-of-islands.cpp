class Solution {
public:
    void bfs(vector<vector<char>>&grid , int& row , int& col , vector<vector<int>>& vis)
    {
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty())
        {
            int curr_row = q.front().first , curr_col = q.front().second;
            q.pop();
            int arr1[4] = {-1,0,0,1} , arr2[4] = {0,-1,1,0};

            for(int i = 0 ; i < 4 ; i++)
            {
                int n_row = curr_row+arr1[i] , n_col = curr_col+arr2[i];
                if(n_row >= 0 and n_col >= 0  and n_row < grid.size() and n_col < grid[0].size() and grid[n_row][n_col] == '1' and !vis[n_row][n_col])
                {
                    vis[n_row][n_col] = 1;
                    q.push({n_row,n_col});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int count = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == '1' and !vis[i][j])
                {
                    count++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};