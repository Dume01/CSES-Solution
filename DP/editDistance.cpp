#include <bits/stdc++.h>
using namespace std;

int fun(int i,int j,string &s,string &w,vector<vector<int>> &dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    
    if(dp[i][j]!=-1)
      return dp[i][j];
    
    if(s[i]==w[j])
    {
        return dp[i][j]=fun(i-1,j-1,s,w,dp);  
    }
    
    int c1=fun(i-1,j-1,s,w,dp);
    int c2=fun(i-1,j,s,w,dp);
    int c3=fun(i,j-1,s,w,dp);
    
    return dp[i][j]=1+min(c1,min(c2,c3));
    
}
int main()
{
  string s,w;
  cin >> s >> w;
  
  vector<vector<int>> dp(s.size()+1,vector<int>(w.size()+1,-1));
  
  cout << fun(s.size()-1,w.size()-1,s,w,dp);
}