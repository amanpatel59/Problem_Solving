// You have given an array A having N elements and an integer S. You have to find a maximum number X such that 
// the sum of all its subarrays of size X is less than or equal to S.
// Example Input:  
//     A = [1, 3, 4, 2]  
//     S = 7  
// Example Output:  
//     2  
// Explanation:  
//     All subarrays of size 2 have the sum less than 7.  
//     Subarays are :  
//     1. [1, 3]  
//     2. [3, 4]  
//     3. [4, 2]  

#include <bits/stdc++.h>
using namespace std;

bool possible(int mid , int& s , vector<int>&a)
{
    int sum = 0;
    for(int i = 0 ; i < mid ; i++)
    {
        sum += a[i];
    }
    if(sum > s)return false;
    int i = 0 , j = mid;
    while(j < a.size())
    {
        sum -= a[i++];
        sum += a[j++];
        if(sum > s)return false;
    }
    return true;
}

int main()
{
    int n , s;
    cin>>n>>s;
    vector<int>a;
    for(int i = 0 ; i < n ; i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }

    int ans = 0 , low = 0 , high = n;
    while(low <= high)
    {
        long long mid = (low+high)/2;
        bool flag = possible(mid,s,a);
        if(flag)
        {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
