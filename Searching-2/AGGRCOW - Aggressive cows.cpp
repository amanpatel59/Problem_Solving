#include <bits/stdc++.h>
using namespace std;

bool possible(int mid , vector<int>&stall_loc , int &c)
{
    int placed = 1;
    int i = 0 , j = 0 ;
    while(j < stall_loc.size())
    {
        if(stall_loc[j] - stall_loc[i] >= mid)
        {
            placed++;
            i = j;
            j++;
        }
        else j++;
    }
    return placed >= c;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int>stall_loc;
        for(int i = 0 ; i < n ; i++)
        {
            int temp;
            cin>>temp;
            stall_loc.push_back(temp);
        }
        sort(stall_loc.begin(),stall_loc.end());
        int low = 1 , high = stall_loc[n-1]-stall_loc[0] , ans = 1;
        while(low <= high)
        {
            long long mid = (low+high)/2;
            bool flag = possible(mid,stall_loc,c);

            if(flag)
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}