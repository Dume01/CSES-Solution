#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main()
{
    int total;
    cin >> total;

    vector<int> dice = {1, 2, 3, 4, 5, 6};
    vector<int> dp(total + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= total; i++)
    {
        for (int d : dice)
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
