#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    long long n;
    cin >> n;
    long long sum=0;
    for(int i=0;i<n-1;i++)
    {   
        int x;
        cin >> x;
        sum+=x;
    }
    long long ans=(n)*(n+1)/2-sum;
    cout << ans;
    return 0;
}