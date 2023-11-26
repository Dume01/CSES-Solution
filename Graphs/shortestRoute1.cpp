// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long n,m;
    cin >> n >> m;
    vector<pair<long long,long long>> adj[n];
    for(long long i=0;i<m;i++)
    {
        long long a,b,c;
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    vector<long long> dis(n,1e18);

    dis[0]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,0});
    vector<int> vis(n,0);
    while(pq.empty()==false)
    {
        long long no=pq.top().second;
        long long d=pq.top().first;
        pq.pop();
        if(vis[no]==1)
            continue;
        vis[no]=1;
        for(auto it:adj[no])
        {
            long long new_n=it.first;
            long long new_d=it.second;
            if(dis[new_n]>new_d+d)
            {
                dis[new_n]=new_d+d;
                pq.push({dis[new_n],new_n});
            }
        }
    }
    for(auto it:dis)
        cout << it << " ";
    return 0;
}
