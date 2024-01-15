#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main()
{   
    int n,total;
    cin >> n >> total;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    vector<int> dp(total + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= total; i++)
    {
        for (int d : arr)
        {
            if (i - d >= 0)
            {
                dp[i] = (dp[i] + dp[i - d]) % mod;
            }
        }
    }

    cout << dp[total] << endl;

    return 0;
}
