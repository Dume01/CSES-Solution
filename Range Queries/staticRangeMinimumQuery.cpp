#include <bits/stdc++.h>
using namespace std;

void build(int i,int low,int high,vector<int> &arr,vector<int> &seg)
{
  
  if(low==high)
  {
    seg[i]=arr[low];
    return;
  }
  int mid=(low+high)/2;
  build(2*i+1,low,mid,arr,seg);
  build(2*i+2,mid+1,high,arr,seg);
  
  seg[i]=min(seg[2*i+1],seg[2*i+2]);
}

int query(int ind,int low,int high,int l,int r,vector<int> &seg)
{
  if(low>=l && high<=r)
  {
    return seg[ind];
  }
  if(low>r || high<l)
  {
    return INT_MAX;
  }
  int mid=(low+high)/2;
  int right=query(ind*2+2,mid+1,high,l,r,seg);
  int left=query(ind*2+1,low,mid,l,r,seg);
  
  return min(left,right);
}
int main()
{
  int n,q;
  cin >> n >> q;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
  vector<int> seg(4*n,0);
  
  build(0,0,n-1,arr,seg);
  
  for(int i=0;i<q;i++)
  {
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    cout << query(0,0,n-1,a,b,seg) << endl;
  }
}