#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<bool> visited;
vector<int> comp;

void dfs(int u) {
    visited[u] = true;
    comp.push_back(u);
    for (int v = 1; v <= n; v++) {
        if (a[u][v] && !visited[v])
            dfs(v);
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

    visited.assign(n+1, false);
    vector<vector<int>> components;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp.clear();
            dfs(i);
            sort(comp.begin(), comp.end());
            components.push_back(comp);
        }
    }

    
    cout << components.size() << "\n";
    for (auto& c : components) {
        for (int i = 0; i < (int)c.size(); i++) {
            if (i > 0) cout << " ";
            cout << c[i];
        }
        cout << "\n";
    }
    return 0;
}
