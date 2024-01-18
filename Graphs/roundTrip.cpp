#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int cnt, unordered_map<int, int>& vis, vector<int> adj[], vector<int>& arr)
{   
    vis[i]=cnt;
    arr.push_back(i+1);
    cnt++;
    for(auto it: adj[i])
    {
        if(vis.find(it)==vis.end())
        {
            dfs(it,cnt,vis,adj,arr);
        }
        else 
        {
            int len=cnt-vis[it];
            if(len>2)
            {
                arr.push_back(it+1);
                cout << (len+1) << endl;
                for(int j=vis[it];j<arr.size();j++)
                    cout << arr[j] << " ";
                exit(0);
                return;   
            }
        }
    }
    arr.pop_back();
    cnt--;
    return;
}

int main() {
    // Write C++ code here
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    unordered_map<int,int> vis;
    vector<int> arr;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()>=1)
        dfs(i,0,vis,adj,arr);   
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}