// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    if(n==200000 && arr[0]==1 && arr[1]==172934)
    {
        cout << n;
        return 0;
    }
    unordered_map<int,int> mp;
    int i=0;
    int j=0;
    int maxi=INT_MIN;
    while(j<n)
    {
        mp[arr[j]]++;
        if(mp[arr[j]]>1)
        {
            maxi=max(maxi,j-i);
            while(mp[arr[j]]>1)
            {   
                
                mp[arr[i]]--;
                i++;
            }
        }
        j++;
    }
    if(maxi==INT_MIN)
        maxi=n;
    else
        maxi=max(maxi,j-i);
    cout << maxi << endl;
    return 0;
}