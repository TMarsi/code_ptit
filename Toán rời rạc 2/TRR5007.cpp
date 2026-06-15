#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int n, s, t, c[105][105];
int a[105], path[105];

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];

    for (int i = 1; i <= n; i++) { a[i] = INF; path[i] = -1; }
    a[s] = 0;

    for (int i = 1; i < n ; i++) {
        for (int u = 1; u <= n; u++) {
            if (a[u] == INF) continue;
            for (int v = 1; v <= n; v++) {
                if (u != v && c[u][v] != INF && a[u] + c[u][v] < a[v]) {
                    a[v] = a[u] + c[u][v];
                    path[v] = u;
                }
            }
        }
    }
    
    bool ok = false;
    for (int u = 1; u <= n; u++) {
        if (a[u] == INF) continue;
        for (int v = 1; v <= n; v++) {
            if (u != v && c[u][v] != INF && a[u] + c[u][v] < a[v])
                ok = true;
        }
    }

    if (ok) {
        cout << -1;
    } else if (a[t] == INF) {
        cout << 0;
    } else {
        cout << a[t] << "\n";
        vector<int> par;
        for (int x = t; x != -1; x = path[x]) par.push_back(x);
        reverse(par.begin(), par.end());
        for (int i = 0; i < (int)par.size(); i++)
            cout << par[i] << (i + 1 < (int)par.size() ? " " : "\n");
    }
    return 0;
}
