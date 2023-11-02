// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {   
        cin >> arr[i];
    }
    long long sum=0;
    long long maxi=INT_MIN;
    for(auto it:arr)
    {
        sum+=it;
        maxi=max(maxi,sum);
        if(sum<0)
        {
            sum=0;
        }
    }
    cout << maxi;
    return 0;
}