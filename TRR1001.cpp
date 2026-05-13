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
        cout << n << " " << edges.size() << "\n";
        for (auto& e : edges)
            cout << e.first << " " << e.second << "\n";
    }
    return 0;
}
