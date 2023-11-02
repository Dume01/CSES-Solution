// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void recPer(int i,string s,vector<string> &ans,set<string> &st)
{
    if(i==s.size() && st.find(s)==st.end())
    {   
        st.insert(s);
        ans.push_back(s);
        return;
    }
    for(int j=i;j<s.size();j++)
    {
        swap(s[i],s[j]);
        recPer(i+1,s,ans,st);
        swap(s[i],s[j]);
    }
}

int main() {
    // Write C++ code here
    string s;
    cin >> s;
    vector<string> ans;
    set<string> st;
    recPer(0,s,ans,st);
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for(auto it:ans)
        cout << it << endl;
    return 0;
}