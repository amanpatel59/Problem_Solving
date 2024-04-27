class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size() , m = grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,-1));
	    queue<pair<int,int>>q;
	    
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < m ; j++){
	            if(grid[i][j]){
	                ans[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    int dr[] = {0, 0, 1, -1};
	    int dc[] = {1, -1, 0 , 0};
	    while(!q.empty()){
	        int r = q.front().first , c = q.front().second;
	        q.pop();
	        for(int i = 0 ; i < 4 ; i++){
	            int nr = r+dr[i] , nc = c+dc[i];
	            if(nr >=0  and nc >= 0 and nr < n and nc < m){
                        if(ans[nr][nc] == -1){
                            ans[nr][nc] = ans[r][c]+1;
                            q.push({nr,nc});
                        }
	            }
	        }
	    }
	    return ans;
	}
};