// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &vis,int i,int j,vector<vector<char>> &ch)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j]=1;
    while(q.empty()==false)
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int x=0;x<4;x++)
        {
            int nr=r+dr[x];
            int nc=c+dc[x];
            if(nr>=0 && nr<ch.size() && nc>=0 && nc<ch[0].size())
            {
                if(vis[nr][nc]==0 && ch[nr][nc]=='.')
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
}
int main() {
    
    int n;
    int m;
    cin >> n >> m;
    vector<vector<char>> ch(n,vector<char>(m,'^'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin >> ch[i][j];
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==0 && ch[i][j]=='.')
            {
                bfs(vis,i,j,ch);    
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
