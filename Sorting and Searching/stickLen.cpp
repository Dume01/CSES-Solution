// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    {   
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    long long ans=0;
    long long median=arr[n/2];
    for(auto it:arr)
    {
        ans+=abs(median-it);
    }
    cout << ans;
    return 0;
}