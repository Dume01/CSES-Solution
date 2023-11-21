#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<int> adj[], vector<int> &dist, vector<int> &prev) {
    queue<int> q;
    q.push(1);  // Uolevi's computer
    dist[1] = 0;
    prev[1] = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (dist[neighbor] == -1) {
                q.push(neighbor);
                dist[neighbor] = dist[current] + 1;
                prev[neighbor] = current;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vector<int> dist(n + 1, -1);
    vector<int> prev(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(n, adj, dist, prev);

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n] + 1 << endl;  // Minimum number of computers on a valid route

        vector<int> route;
        for (int at = n; at != -1; at = prev[at]) {
            route.push_back(at);
        }

        reverse(route.begin(), route.end());

        for (int node : route) {
            cout << node << " ";
        }
    }

    return 0;
}
