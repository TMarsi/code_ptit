#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    vector<bool> visited(n+1, false);
    vector<vector<int>> components;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            
            vector<int> comp;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                comp.push_back(u);
                for (int v = 1; v <= n; v++) {
                    if (a[u][v] && !visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
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
