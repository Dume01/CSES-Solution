#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n,0);
    for(int i=0;i<n;i++)
      cin >> a[i];
      
    ll ans=0;
    for(int i=1;i<n;i++)
    { 
      ll diff=a[i]-a[i-1];
      if(diff<0)
      {
          ans+=(-1*diff);
          a[i]=a[i-1];      
      }
    }
    cout << ans;
}