bool checking(vector<int>& arr, int n, int m, int mid)
{
    int temp_m = 1 , sum = 0;
    for(auto i: arr)
    {
        if(sum+i <=mid)
        {
            sum+=i;
        }
        else
        {
            sum = i;
            temp_m++;
        }
    }
    if(temp_m<=m)return true;
    
    return false; 
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = -1 , high = 0 , ans = -1;
    for(auto i : arr)
    {
        low = max(low,i);
        high += i;
    }

    while(low<=high)
    {
        int mid = low+(high-low)/2;
        bool check = checking(arr,n,m,mid);
        if(check)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return low;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    return findPages(boards,boards.size(),k);
}