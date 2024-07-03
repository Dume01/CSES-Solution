#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n,q;
  cin >> n >> q;
  vector<long long> arr(n+1);
  long long sum=0;
  for(int i=0;i<n;i++)
  { 
    arr[i]=sum;
    long long x;
    cin >> x;
    sum+=x;
  }
  arr[n]=sum;
  for(int i=0;i<q;i++)
  {
    int a,b;
    cin >> a >> b;
    a--;
    cout << (arr[b]-arr[a]) << endl;
  }
}
