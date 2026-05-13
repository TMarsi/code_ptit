#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    int n, s, t;
    cin >> n >> s >> t;

    vector<vector<int>> c(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++) c[i][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    
    vector<int> dist(n+1, INF);
    vector<int> parent(n+1, -1);
    vector<bool> visited(n+1, false);
    dist[s] = 0;

    for (int iter = 0; iter < n; iter++) {
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (u == -1 || dist[u] == INF) break;
        visited[u] = true;
        for (int v = 1; v <= n; v++) {
            if (c[u][v] < INF && dist[u] + c[u][v] < dist[v]) {
                dist[v] = dist[u] + c[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[t] == INF) {
        cout << 0 << "\n";
    } else {
        cout << dist[t] << "\n";
        
        vector<int> path;
        int cur = t;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < (int)path.size(); i++) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << "\n";
    }
    return 0;
}
