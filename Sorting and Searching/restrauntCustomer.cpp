#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<pair<int,bool>> p;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        p.push_back({x,true});
        p.push_back({y,false});
    }
    sort(p.begin(),p.end());
    int cnt=0;
    int maxi=0;
    for(int i=0;i<p.size();i++)
    {
      if(p[i].second==true)
        cnt++;
      else
      {
        maxi=max(maxi,cnt);
        cnt--;
      }
    }
    cout << maxi << endl;
    return 0;
}
