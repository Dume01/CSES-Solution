// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

long long int binpow(long long a, long long b, long long m)
{
    long long ans = 1;
    while(b)
    {
        if(b % 2)
        {
            ans = (ans * a) % m;
        }
        a = a * a % m;
        b /= 2;
    }
    return ans;
}
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    cout<<binpow(2,n,1000000007);
}