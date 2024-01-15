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
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[index]=arr[i];
        }
    }
    cout << temp.size() <<endl;
    return 0;
}