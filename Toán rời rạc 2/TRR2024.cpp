#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;

int countComponents(int skip) {
    vector<bool> vis(n+1, false);
    if (skip >= 1) vis[skip] = true;
    int comps = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            comps++;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v = 1; v <= n; v++) {
                    if (a[u][v] && !vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return comps;
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    a.assign(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int baseComps = countComponents(0);

    vector<int> result;
    for (int i = 1; i <= n; i++) {
        int comps = countComponents(i);
        if (comps > baseComps)
            result.push_back(i);
    }

    sort(result.begin(), result.end());
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
