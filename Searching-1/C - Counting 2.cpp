#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n , q;
  cin>>n>>q;
  vector<int>a;
  
  for(int i = 0 ; i < n ; i++)
  {
    int temp;
    cin>>temp;
    a.push_back(temp);
  }
  vector<int>queries;
  for(int i = 0 ; i < q ; i++)
  {
    int temp;
    cin>>temp;
    queries.push_back(temp);
  }
  
  sort(a.begin(),a.end());
  vector<int>res;
  for(int i = 0 ; i < queries.size() ; i++)
  {
    int low = 0 , high = a.size()-1 , ans = 0;
    while(low <= high)
    {
      long long mid = (low+high)/2;
      if(a[mid] >= queries[i])
      {
        ans = a.size()-mid;
        high = mid-1;
      }
      else low = mid+1;
    }
    res.push_back(ans);
  }
  for(auto i : res)cout<<i<<endl;
  return 0;
}