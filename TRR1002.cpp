#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    vector<int> deg(n+1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j]) deg[i]++;

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            cout << deg[i];
        }
        cout << "\n";
    } else {
        
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            vector<int> neighbors;
            for (int j = 1; j <= n; j++)
                if (a[i][j]) neighbors.push_back(j);
            sort(neighbors.begin(), neighbors.end());
            cout << neighbors.size();
            for (int v : neighbors) cout << " " << v;
            cout << "\n";
        }
    }
    return 0;
}
