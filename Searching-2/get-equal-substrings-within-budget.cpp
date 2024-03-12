class Solution {
public:
    bool possible(string& s , string& t , int len , int maxCost)
    {   int cost = 0 , low = 0 , high = 0 , minCost = INT_MAX;
        while(high < s.size())
        {
            cost += abs(s[high]-t[high]);
            if(high-low+1 < len)
            {
                high++;
            }
            else
            {
                minCost = min(cost,minCost);
                cost -= abs(s[low]-t[low]);
                low++;
                high++;
            }
        }
        if(minCost <= maxCost)return true;
        return false;
    }

    int equalSubstring(string s, string t, int maxCost) {
        // SLIDING WINDOW

        // int i = 0 , j = 0 , ans = 0;

        // while(j < s.size())
        // {
        //     maxCost -= abs(s[j]-t[j]);

        //     if(maxCost >= 0)
        //     {
        //         ans = max(ans,j-i+1);
        //         j++;
        //     }
        //     else
        //     {
        //         while(i <= j and maxCost < 0)
        //         {
        //             maxCost += abs(s[i]-t[i]);
        //             i++;
        //         }
        //         ans = max(ans,j-i+1);
        //         j++;
        //     }
        // }
        // return ans;


        // BINARY SEARCH
        int low = 0 , high = s.size() , ans = 0;

        while(low <= high)
        {
            long long mid = (low+high)/2;
            bool flag = possible(s,t,mid,maxCost);
            if(flag)
            {
                ans = max(ans,(int)mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};