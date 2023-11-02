#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    if(n==1)
    {
        cout << "1";
        return 0;
    }
    if(n==2 ||n==3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    vector<int> ans1;
    vector<int> ans2;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
            ans1.push_back(i);
        else
            ans2.push_back(i);
    }
    for(auto it:ans1)
        cout << it << " ";
    for(auto it:ans2)
        cout << it << " ";
    return 0;
}