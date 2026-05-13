#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;

    vector<vector<int>> c(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++) c[i][i] = 0;

    vector<int> deg(n+1, 0);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
        c[v][u] = w;
        deg[u]++;
        deg[v]++;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            cout << deg[i];
        }
        cout << "\n";
    } else {
        
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j > 1) cout << " ";
                cout << c[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
