// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    vector<pair<long long,long long>> arr;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    long long cost=0;
    long long st=0;
    for(auto it:arr)
    {
        cost+=it.second-st-it.first;
        st+=it.first;
    }
    cout << cost << endl;
    return 0;
}