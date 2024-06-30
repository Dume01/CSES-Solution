#include <bits/stdc++.h>
using namespace std;

int fun(int n,vector<int> &dp)
{
  if(n==0)
    return 0;
  if(n<0)
    return 1e9;
    
  if(dp[n]!=-1)
    return dp[n];
  
  vector<int> arr;
  int t=n;
  while(t>0)
  {
    int d=t%10;
    t/=10;
    arr.push_back(d);
  }
  int a=0;
  int ans=INT_MAX;
  for(int i=0;i<arr.size();i++)
  {   
      if(arr[i] != 0)
     {  
        a=1+fun(n-arr[i],dp);
        ans=min(ans,a);
     }
  }
  return dp[n]=ans;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << fun(n,dp);
}