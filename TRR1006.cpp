#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;

    vector<pair<int,int>> edges;
    vector<int> deg(n+1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edges.push_back({u, v});
        deg[u]++;
        deg[v]++;
    }
    
    sort(edges.begin(), edges.end());

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            cout << deg[i];
        }
        cout << "\n";
    } else {
        
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
