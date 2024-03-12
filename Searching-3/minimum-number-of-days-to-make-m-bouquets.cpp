class Solution {
public:
    bool possible(vector<int>&bloomDay , int m , int k , int mid)
    {
        int curr = 0 , bouquets = 0;
        for(int i = 0 ; i < bloomDay.size() ; i++)
        {
            if(bloomDay[i] <= mid)
            {
                curr++;
            }
            else curr = 0;
            if(curr == k)
            {
                bouquets++;
                curr = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end()) , high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(low <= high)
        {
            long long mid = (low+high)/2;
            bool flag = possible(bloomDay,m,k,mid);

            if(flag)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};