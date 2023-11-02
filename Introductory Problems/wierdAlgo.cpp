// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    vector<long long> ans;
    long long n;
    cin >> n;
    set<long long> st;
    if(n==1)
    {
        cout << 1 ;
        return 0;
    }
    ans.push_back(n);
    while(n!=1)
    {   
        if(st.find(n)==st.end())
        {   
            st.insert(n);
            if(n%2==0)
            {
                n=n/2;
                ans.push_back(n);
            }
            else
            {
                n=n*3+1;
                ans.push_back(n);
            }
        }
        else
        {
            break;
        }
    }
    if(ans[ans.size()-1]==1)
    {
        for(auto it: ans)
        {
            cout << it << " ";
        }
    }
    return 0;
}