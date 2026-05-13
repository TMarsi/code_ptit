#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;

    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    vector<int> indeg(n+1, 0), outdeg(n+1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        outdeg[u]++;
        indeg[v]++;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << indeg[i] << " " << outdeg[i] << "\n";
    } else {
        
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j > 1) cout << " ";
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
