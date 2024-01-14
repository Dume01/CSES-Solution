// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
    // Write C++ code here
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
        
    vector<vector<int>> dp(n,vector<int>(k+1,1e9));
    for(int i=0;i<=k;i++)
    {
        if(i%arr[0]==0)
            dp[0][i]=i/arr[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int s=0;s<=k;s++)
        {
            int t=1e9,nt=1e9;
            if(arr[i]<=s)
            {
                t=1+dp[i][s-arr[i]];
            }
            nt=dp[i-1][s];
            dp[i][s]=min(t,nt);
        }
    }
    if(dp[n-1][k]==1e9)
        cout << "-1";
    else
    cout << dp[n-1][k];
    return 0;
}
