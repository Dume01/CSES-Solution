// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void bfs(int i,vector<int> arr[],vector<int> &vis)
{
    queue<int> q;
    q.push(i);
    vis[i]=1;
    while(!q.empty())
    {
        int nex=q.front();
        q.pop();
        for(auto it:arr[nex])
        {
            if(vis[it]==0)
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

int main() {
    // Write C++ code here
    int n,m;
    cin >> n >> m;
    vector<int> arr[n];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }
    vector<int> vis(n,0);
    int cnt=0;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {   
            if(i!=0)
            {
                cnt++;
                ans.push_back({1,i+1});
            }
            bfs(i,arr,vis);
        }
    }
    cout << cnt << endl;
    for(auto it:ans)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}