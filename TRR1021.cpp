#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> c(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    vector<int> indeg(n+1, 0), outdeg(n+1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && c[i][j] < INF) {
                outdeg[i]++;
                indeg[j]++;
            }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << indeg[i] << " " << outdeg[i] << "\n";
    } else {
        
        vector<tuple<int,int,int>> edges;
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                if (u != v && c[u][v] < INF)
                    edges.push_back({u, v, c[u][v]});
        sort(edges.begin(), edges.end());
        cout << n << " " << edges.size() << "\n";
        for (auto& [u, v, w] : edges)
            cout << u << " " << v << " " << w << "\n";
    }
    return 0;
}
