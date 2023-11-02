#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    int sum=0;
    int x=5;
    while((n/x)!=0)
    {
        sum+=floor(n/x);
        x=x*5;
    }
    cout << sum;
    return 0;
}