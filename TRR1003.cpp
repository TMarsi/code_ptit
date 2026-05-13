#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    vector<int> deg(n+1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j]) deg[i]++;

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            cout << deg[i];
        }
        cout << "\n";
    } else {
        
        vector<pair<int,int>> edges;
        for (int u = 1; u <= n; u++)
            for (int v = u+1; v <= n; v++)
                if (a[u][v])
                    edges.push_back({u, v});
        int m = edges.size();
        cout << n << " " << m << "\n";
        for (int i = 1; i <= n; i++) {
            for (int e = 0; e < m; e++) {
                int val = 0;
                if (edges[e].first == i || edges[e].second == i) val = 1;
                if (e > 0) cout << " ";
                cout << val;
            }
            cout << "\n";
        }
    }
    return 0;
}
