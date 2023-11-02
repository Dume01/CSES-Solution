// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        vec.push_back({y,x});
    }
    sort(vec.begin(),vec.end());
    int cnt=1;
    int lastEnd=vec[0].first;
    for(int i=1;i<n;i++)
    {
        if(vec[i].second>=lastEnd)
        {   
            lastEnd=vec[i].first;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}