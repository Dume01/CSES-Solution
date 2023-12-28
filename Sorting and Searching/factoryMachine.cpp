// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

long long int fun(vector<long long int> &arr,long long int mid)
{   
    long long int x=0;
    for(int i=0;i<arr.size();i++)
    {
        x+=min(mid/arr[i],(long long int)1e9);
    }
    return x;
}

int main() {
    // Write C++ code here
    int n,k;
    cin >> n >> k;
    vector<long long int> arr(n,0);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    long long int low=0;
    long long int high=1e18;
    long long int ans=1e18;
    while(low<=high)
    {
        long long int mid=(low+high)/2;
        long long int pro=fun(arr,mid);
        if(pro>=k)
        {
            high=mid-1;
            ans=min(ans,mid);
        }
        else
        {
            low=mid+1;
        }
    }
    cout << ans;
    return 0;
}