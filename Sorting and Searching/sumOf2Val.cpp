// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    map<int,int> mp;
    mp[arr[0]]=0;
    for(int i=1;i<n;i++)
    {
        int diff=x-arr[i];
        if(mp.find(diff)!=mp.end())
        {
            cout << (mp[diff]+1) << " " << (i+1) << endl;
            return 0;
        }
        mp[arr[i]]=i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}