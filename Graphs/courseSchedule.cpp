#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[b-1].push_back(a-1);
    }
    int indegree[n]={0};
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
            indegree[it]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
        if(indegree[i]==0)
            q.push(i);
    vector<int> ans;
    while(q.empty()==false)
    {
        int n=q.front();
        q.pop();
        ans.push_back(n);
        for(auto it:adj[n])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    if(ans.size()==0 || ans.size()!=n)
        cout << "IMPOSSIBLE";
    else
        for(int i=n-1;i>=0;i--)
            cout << (ans[i]+1) << " ";
    return 0;
}
