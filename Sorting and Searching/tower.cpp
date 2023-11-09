// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        int ub=upper_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
        if(ub==ans.size())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans[ub]=arr[i];
        }
    }
    cout << ans.size();
    return 0;
}