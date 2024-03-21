#include <bits/stdc++.h>
using namespace std;

bool check_possibility(long long mid , vector<long long>&a , vector<long long>&b , long long k)
{
    long long i = 0 , j = 0 , time_taken = 0;

    while ((size_t)i < a.size() && (size_t)j < b.size() && mid > 0)
    {
        if(time_taken > k) return false;
        if(a[i] <= b[j])
        {
            time_taken += a[i++];
        }
        else time_taken += b[j++];
        mid--;
    }

    while((size_t)i < a.size() && mid > 0)
    {
        if(time_taken > k) return false;
        time_taken += a[i++];
        mid--;
    }
    
    while((size_t)j < b.size() && mid > 0)
    {
        if(time_taken > k) return false;
        time_taken += b[j++];
        mid--;
    }

    return time_taken <= k;
}

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    vector<long long>a,b;

    for(int i = 0 ; i < n ; i++)
    {
        long long temp;
        cin>>temp;
        a.push_back(temp);
    }

    for(int i = 0 ; i < m ; i++)
    {
        long long temp;
        cin>>temp;
        b.push_back(temp);
    }

    // search space => minimum can read => 0 and maximum can read => all =>m+n

    long long low = 0 , high = n+m , ans = 0;

    while(low <= high)
    {
        long long mid = low + (high-low)/2;
        
        bool flag = check_possibility(mid,a,b,k);
        
        if(flag)
        {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    cout<<ans;
    return 0;
}
