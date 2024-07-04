#include <bits/stdc++.h>
using namespace std;

typedef int long_long;

void build(int i,int low,int high,vector<long long> &arr,vector<long long> &seg)
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
int query(int ind,int low,int high,int l,int r,vector<long long> &seg)
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

void update(int ind,int low,int high,int i,int val,vector<long long> &seg)
{
  if(low==high)
  {
    seg[ind]=val;
    return;
  }
  int mid=(low+high)/2;
  
  if(i<=mid)
    update(ind*2+1,low,mid,i,val,seg);
  else
    update(ind*2+2,mid+1,high,i,val,seg);
  
  seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
  
}

int main()
{
  int n,q;
  cin >> n >> q;
  vector<long long> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
  vector<long long> seg(4*n,0);
  
  build(0,0,n-1,arr,seg);
  
  for(int i=0;i<q;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a==2)
    {
        c--;
        b--;
        cout << query(0,0,n-1,b,c,seg) << endl;      
    }
    else
    { 
      b--;
      update(0,0,n-1,b,c,seg);
    }

  }
}