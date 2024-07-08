#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n,k;
  cin >> n >> k;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
    
  long long cnt=0;
  int i=0,j=0;
  
  unordered_map<int,int> mp;
  
  while(j<n)
  {
      mp[arr[j]]++;
      //cout << i << " " << j << endl;
      int sz=mp.size();
      if(sz>k)
      {
        while(mp.size()>k)
        {
          mp[arr[i]]--;
          if(mp[arr[i]]==0)
            mp.erase(arr[i]);
          i++;
        }
      }
      
      cnt+=(j-i+1);
      
      j++;
  }
  
  cout << cnt << endl;
}