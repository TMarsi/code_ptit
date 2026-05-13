#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<int> disc, low, par;
vector<bool> visited;
vector<pair<int,int>> bridges;
int timer_cnt;

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = timer_cnt++;
    for (int v = 1; v <= n; v++) {
        if (!a[u][v]) continue;
        if (!visited[v]) {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                int x = min(u, v), y = max(u, v);
                bridges.push_back({x, y});
            }
        } else if (v != par[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    a.assign(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    disc.assign(n+1, 0);
    low.assign(n+1, 0);
    par.assign(n+1, -1);
    visited.assign(n+1, false);
    timer_cnt = 0;

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);

    sort(bridges.begin(), bridges.end());
    cout << bridges.size() << "\n";
    for (auto& [u, v] : bridges)
        cout << u << " " << v << "\n";
    return 0;
}
