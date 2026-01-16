#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long ans=0;
    long long maxi=1;
    for(int i=1;i<s.size();i++)
    {
      if(s[i]==s[i-1])
        maxi++;
      else
      {
        ans=max(ans,maxi);
        maxi=1;
      }
    }
    ans=max(ans,maxi);
    cout << ans;
}