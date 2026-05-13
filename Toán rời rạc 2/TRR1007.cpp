#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> a(n+1, vector<int>(n+1, 0));

    
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            a[i][v] = 1;
            a[v][i] = 1;
        }
    }

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
            for (int j = 1; j <= n; j++) {
                if (j > 1) cout << " ";
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
