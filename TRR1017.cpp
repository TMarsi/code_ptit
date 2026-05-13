#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;

    vector<pair<int,int>> edges_list;
    vector<int> indeg(n+1, 0), outdeg(n+1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges_list.push_back({u, v});
        outdeg[u]++;
        indeg[v]++;
    }
    sort(edges_list.begin(), edges_list.end());

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << indeg[i] << " " << outdeg[i] << "\n";
    } else {
        
        cout << n << " " << m << "\n";
        for (int i = 1; i <= n; i++) {
            for (int e = 0; e < m; e++) {
                int val = 0;
                if (edges_list[e].first == i) val = 1;
                else if (edges_list[e].second == i) val = -1;
                if (e > 0) cout << " ";
                cout << val;
            }
            cout << "\n";
        }
    }
    return 0;
}
