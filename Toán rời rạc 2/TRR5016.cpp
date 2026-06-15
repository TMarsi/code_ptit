#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int n;
int d[105][105], nxt[105][105];

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
            nxt[i][j] = j;
        }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }

    int bu = -1, bv = -1, best = -1;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            if (u != v && d[u][v] < INF && d[u][v] > best) {
                best = d[u][v]; bu = u; bv = v;
            }

    if (bu == -1) {
        cout << 0;
    } else {
        cout << bu << " " << bv << " " << best << "\n";
        vector<int> path;
        int cur = bu;
        path.push_back(cur);
        while (cur != bv) {
            cur = nxt[cur][bv];
            path.push_back(cur);
        }
        for (int i = 0; i < (int)path.size(); i++)
            cout << path[i] << (i + 1 < (int)path.size() ? " " : "\n");
    }
    return 0;
}
