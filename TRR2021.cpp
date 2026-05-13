#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<int> disc, low, parent_arr;
vector<bool> visited;
vector<bool> isAP;
int timer_cnt;

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = timer_cnt++;
    int children = 0;

    for (int v = 1; v <= n; v++) {
        if (!a[u][v]) continue;
        if (!visited[v]) {
            children++;
            parent_arr[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            
            
            if (parent_arr[u] == -1 && children > 1)
                isAP[u] = true;
            
            if (parent_arr[u] != -1 && low[v] >= disc[u])
                isAP[u] = true;
        } else if (v != parent_arr[u]) {
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
    parent_arr.assign(n+1, -1);
    visited.assign(n+1, false);
    isAP.assign(n+1, false);
    timer_cnt = 0;

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);

    vector<int> result;
    for (int i = 1; i <= n; i++)
        if (isAP[i]) result.push_back(i);

    cout << result.size() << "\n";
    if (!result.empty()) {
        for (int i = 0; i < (int)result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }
    return 0;
}
