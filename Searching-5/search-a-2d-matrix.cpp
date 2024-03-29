bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , n = matrix[0].size();
        int low = 0 , high = (m*n)-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(matrix[mid/n][mid%n]==target)
            {
                return true;
            }
            else if(matrix[mid/n][mid%n] < target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return false;
    }