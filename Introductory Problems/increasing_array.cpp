
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<long long> vec;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin >> x;
        vec.push_back(x);
    }
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        if(vec[i]<vec[i-1])
        {
            ans+=vec[i-1]-vec[i];
            vec[i]=vec[i-1];
        }
    }
    cout << ans;
    return 0;
}