#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n,maxi;
  cin >> n;
  maxi=-1e9;
  long long sum=0;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
  {
      cin >> arr[i];
      maxi=max(maxi,arr[i]);
      sum+=arr[i];
  }
  sum-=maxi;
  if(sum<maxi)
  {
    cout << (2*(long long)maxi) << endl;
  }
  else
  {
    sum+=maxi;
    cout << sum << endl;
  }
  return 0;
}