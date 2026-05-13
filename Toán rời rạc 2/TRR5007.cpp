#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    int n, s, t;
    cin >> n >> s >> t;

    vector<vector<int>> c(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++) c[i][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    
    vector<tuple<int,int,int>> edges;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && c[i][j] < INF)
                edges.push_back({i, j, c[i][j]});

    vector<long long> dist(n+1, LLONG_MAX);
    vector<int> parent(n+1, -1);
    dist[s] = 0;

    
    for (int iter = 0; iter < n - 1; iter++) {
        bool updated = false;
        for (auto& [u, v, w] : edges) {
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = true;
            }
        }
        if (!updated) break;
    }

    
    
    
    vector<bool> inNegCycle(n+1, false);
    for (auto& [u, v, w] : edges) {
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
            inNegCycle[v] = true;
        }
    }
    
    for (int iter = 0; iter < n; iter++) {
        for (auto& [u, v, w] : edges) {
            if (inNegCycle[u]) inNegCycle[v] = true;
        }
    }

    if (inNegCycle[t]) {
        cout << -1 << "\n";
    } else if (dist[t] == LLONG_MAX) {
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
