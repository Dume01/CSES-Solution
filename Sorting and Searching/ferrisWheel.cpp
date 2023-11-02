// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n,x;
    cin >> n >> x;
    vector<int> wt(n,0);
    for(int i=0;i<n;i++)
        cin >> wt[i];
    sort(wt.begin(),wt.end());
    vector<int> tenp=wt;
    int cnt=0;
    vector<int> vis(n,0);
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int sum=wt[i]+wt[j];
        if(sum<=x)
        {
            cnt++;
            i++;
            j--;
        }
        else if(sum>x)
        {
            cnt++;
            j--;
        }
    }
    if(i==j)
        cnt++;
    cout << cnt << endl;
    return 0;
}