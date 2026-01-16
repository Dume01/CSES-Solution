#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {  cout << "1";
       return 0;
    }
    if(n==3 || n==2)
    {
      cout << "NO SOLUTION";
      return 0;
    }
    
    vector<int> a1;
    vector<int> a2;
    
    for(int i=1;i<=n;i++)
      if(i%2==0)
        a1.push_back(i);
      else
        a2.push_back(i);
        
    for(auto it:a1)
      cout << it << " ";
    for(auto it:a2)
      cout << it << " ";
}