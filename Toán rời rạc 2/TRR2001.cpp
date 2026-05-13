#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<int> path;
bool found;

void dfs(int cur, int target, vector<bool>& visited) {
    if (cur == target) {
        found = true;
        return;
    }
    for (int v = 1; v <= n && !found; v++) {
        if (a[cur][v] && !visited[v]) {
            visited[v] = true;
            path.push_back(v);
            dfs(v, target, visited);
            if (!found) {
                path.pop_back();
                visited[v] = false;
            }
        }
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    int t, u, v;
    cin >> t >> n >> u >> v;

    a.assign(n+1, vector<int>(n+1, 0));
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
        
        vector<bool> visited(n+1, false);
        visited[u] = true;
        path.push_back(u);
        found = false;
        dfs(u, v, visited);
        if (!found) {
            cout << 0 << "\n";
        } else {
            for (int i = 0; i < (int)path.size(); i++) {
                if (i > 0) cout << " ";
                cout << path[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
