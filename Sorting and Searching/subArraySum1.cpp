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
    int i=0;
    int j=0;
    int sum=0;
    int cnt=0;
    while(j<n)
    {
        sum+=arr[j];
        if(sum < x)
        {
            j++;
        }
        else
        {
            while(sum>=x)
            {   
                if(sum==x)
                    cnt++;
                sum-=arr[i];
                i++;
            }
            j++;
        }
    }
    cout << cnt;
}