// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// int fun(int i,int j,vector<vector<char>> &grid,int n)
// {
//     if(i>=n || j>=n || grid[i][j]=='*')
//         return 0;
//     if(i==n-1 && j==n-1)
//         return 1;
//     int down=fun(i+1,j,grid,n);
//     int right=fun(i,j+1,grid,n);
//     return down+right;
// }

int main() {
    // Write C++ code here
    int n;
    int mod=1000000007;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin >> grid[i][j];
    }
    //int cnt=fun(0,0,grid,n);
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]=='*')
                dp[i][j]=0;
            else if(i==0 && j==0)
                dp[i][j]=1;
            else
            {   long long up=0,left=0;
                if(i>0)
                    up=dp[i-1][j]%mod;
                if(j>0)
                    left=dp[i][j-1]%mod;
                dp[i][j]=(up%mod+left%mod)%mod;
            }
        }
    }
    long long cnt=dp[n-1][n-1]%mod;
    cout << cnt;
    return 0;
}