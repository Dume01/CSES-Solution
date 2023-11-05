#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        arr.push_back({x,i+1});
    }
        
    sort(arr.begin(),arr.end());
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
        bool f=0;
        while(j<k)
        {
            long long sum=arr[i].first+arr[j].first+arr[k].first;
            //cout << arr[i].first << " " << arr[j].first <<  " " << arr[k].first << endl;
            if(sum==x)
            {
                a.push_back(arr[i].second);
                a.push_back(arr[j].second);
                a.push_back(arr[k].second);
                f=1;
                break;
            }
            else if(sum<x)
                j++;
            else
                k--;
        }
        if(f)
            break;
    }
    if(a.size()==3)
    {
        sort(a.begin(),a.end());
        for(auto it : a)
            cout << it << " ";
        return 0;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
