#include <bits/stdc++.h>
using namespace std;

int bfs(int i, vector<int> &vis, vector<int> arr[], vector<int> &ans)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    if (i == 0)
        ans[0] = 1;
    else
        ans[i] = 2;
    while (q.empty() == false)
    {
        int n = q.front();
        q.pop();
        for (auto it : arr[n])
        {
            if (vis[it] == 0)
            {
                if (ans[n] == 1)
                    ans[it] = 2;
                else
                    ans[it] = 1;
                q.push(it);  // Push 'it' to the queue here
                vis[it] = 1;  // Move this line inside the if block
            }
            else if (ans[it] == ans[n])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a - 1].push_back(b - 1);
        arr[b - 1].push_back(a - 1);
    }
    vector<int> vis(n, 0);
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            int f = bfs(i, vis, arr, ans);
            if (!f)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}
