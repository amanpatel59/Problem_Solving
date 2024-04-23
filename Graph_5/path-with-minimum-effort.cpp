class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size() , cols = heights[0].size();
        vector<vector<int>>efforts_needed(rows,vector<int>(cols,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>minh;

        // initially at
        efforts_needed[0][0] = 0;
        minh.push({0,0,0});

        while(!minh.empty())
        {
            auto [curr_efforts , curr_row , curr_col] = minh.top();
            minh.pop();

            if(curr_row == rows-1 and curr_col == cols-1)return curr_efforts;
            
            int a[4] = {0,0,-1,1} , b[4] = {1,-1,0,0};
            for(int i = 0 ; i < 4 ; i++)
            {
                int nrow = curr_row + a[i] , ncol = curr_col + b[i];
                if(nrow >= 0 and ncol >= 0 and nrow < rows and ncol < cols)
                {
                    int efforts = abs(heights[nrow][ncol] - heights[curr_row][curr_col]);
                    if(efforts_needed[nrow][ncol] > max(curr_efforts,efforts))
                    {
                        efforts_needed[nrow][ncol] = max(curr_efforts,efforts);
                        minh.push({efforts_needed[nrow][ncol] , nrow , ncol});
                    }
                }
            }
        }
        return efforts_needed[rows-1][cols-1];
    }
};