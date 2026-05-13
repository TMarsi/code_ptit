#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    int t, n, u, v;
    cin >> t >> n >> u >> v;

    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    if (t == 1) {
        
        int count = 0;
        for (int w = 1; w <= n; w++) {
            if (w != u && w != v && a[u][w] && a[w][v])
                count++;
        }
        cout << count << "\n";
    } else {
        
        vector<int> parent(n+1, -1);
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        bool found = false;

        while (!q.empty() && !found) {
            int cur = q.front(); q.pop();
            for (int w = 1; w <= n; w++) {
                if (a[cur][w] && !visited[w]) {
                    visited[w] = true;
                    parent[w] = cur;
                    if (w == v) { found = true; break; }
                    q.push(w);
                }
            }
        }

        if (!found) {
            cout << 0 << "\n";
        } else {
            vector<int> path;
            int cur = v;
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
    }
    return 0;
}
