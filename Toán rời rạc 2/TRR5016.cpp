#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> c(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++) c[i][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<vector<int>> next_v(n+1, vector<int>(n+1, -1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            dist[i][j] = c[i][j];
            if (c[i][j] < INF) next_v[i][j] = j;
        }
    for (int i = 1; i <= n; i++) { dist[i][i] = 0; next_v[i][i] = i; }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next_v[i][j] = next_v[i][k];
                }

    
    int maxDist = -1;
    int bestU = -1, bestV = -1;

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u == v) continue;
            if (dist[u][v] < INF) {
                if (dist[u][v] > maxDist ||
                    (dist[u][v] == maxDist && make_pair(u,v) < make_pair(bestU,bestV))) {
                    maxDist = dist[u][v];
                    bestU = u;
                    bestV = v;
                }
            }
        }
    }

    if (bestU == -1) {
        cout << 0 << "\n";
    } else {
        cout << bestU << " " << bestV << " " << maxDist << "\n";
        
        vector<int> path;
        int cur = bestU;
        while (cur != bestV) {
            path.push_back(cur);
            cur = next_v[cur][bestV];
        }
        path.push_back(bestV);
        for (int i = 0; i < (int)path.size(); i++) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << "\n";
    }
    return 0;
}
