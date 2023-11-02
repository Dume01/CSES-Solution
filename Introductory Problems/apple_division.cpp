// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void fun(int i,vector<long long> &arr,long long sum,long long &mini,long long s)
{
    if(i==arr.size())
    {   
        //cout << (sum-s) << " " << s << endl;
        mini=min(mini,abs((sum-s)-(s)));
        return;
    }
    
    s+=arr[i];
    fun(i+1,arr,sum,mini,s);
    s-=arr[i];
    fun(i+1,arr,sum,mini,s);
}

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<long long> arr;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin >> x;
        sum+=x;
        arr.push_back(x);
    }
    long long mini=1e12;
    fun(0,arr,sum,mini,0);
    cout << mini;
    return 0;
}