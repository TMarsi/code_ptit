#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;

void dfs_directed(int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v = 1; v <= n; v++)
        if (a[u][v] && !visited[v])
            dfs_directed(v, visited);
}

void dfs_undirected(int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v = 1; v <= n; v++)
        if ((a[u][v] || a[v][u]) && !visited[v])
            dfs_undirected(v, visited);
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    a.assign(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    
    vector<bool> vis(n+1, false);
    dfs_undirected(1, vis);
    bool weakly = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) { weakly = false; break; }

    if (!weakly) {
        cout << 0 << "\n";
        return 0;
    }

    
    fill(vis.begin(), vis.end(), false);
    dfs_directed(1, vis);
    bool fwd = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) { fwd = false; break; }

    if (!fwd) {
        cout << 2 << "\n";
        return 0;
    }

    
    
    fill(vis.begin(), vis.end(), false);
    vis[1] = true;
    
    stack<int> st;
    st.push(1);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v = 1; v <= n; v++) {
            if (a[v][u] && !vis[v]) {
                vis[v] = true;
                st.push(v);
            }
        }
    }
    bool bwd = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) { bwd = false; break; }

    if (fwd && bwd) cout << 1 << "\n";
    else cout << 2 << "\n";

    return 0;
}
