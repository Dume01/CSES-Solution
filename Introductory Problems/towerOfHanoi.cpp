#include <bits/stdc++.h>

using namespace std;

void towerOfHanoi(int n, int source,int aux, int dest,vector<pair<int,int>> &ans) 
{
  if (n == 0) {
    return;
  }
  towerOfHanoi(n - 1, source, dest, aux,ans);
  ans.push_back({source,dest});
  towerOfHanoi(n - 1, aux, source, dest,ans);
}

int main() {
  int n;
  cin >> n;// Number of disks
  vector<pair<int,int>> ans;
  towerOfHanoi(n, 1,2,3,ans); // A, B and C are names of rods
  cout << ans.size() << endl;
  for(auto it:ans)
    cout << it.first << " " << it.second << endl;
  return 0;
}