// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        mp[arr[i]]=i;
    }
    int cnt=1;
    int x=0;
    for(int i=2;i<=n;i++)
    {
        if(mp[i]>mp[i-1])
        {
            x++;
        }
        else
        {
            x=0;
        }
        
        if(x==0)
            cnt++;
    }
    cout << cnt;
}