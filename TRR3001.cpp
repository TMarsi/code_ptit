#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;

bool isConnected() {
    vector<bool> vis(n+1, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 1; v <= n; v++)
            if (a[u][v] && !vis[v]) { vis[v] = true; q.push(v); }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) return false;
    return true;
}

vector<int> hierholzer(int start) {
    
    vector<vector<int>> rem = a;
    stack<int> st;
    vector<int> circuit;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        bool found = false;
        for (int v = 1; v <= n; v++) {
            if (rem[u][v] > 0) {
                rem[u][v]--;
                rem[v][u]--;
                st.push(v);
                found = true;
                break;
            }
        }
        if (!found) {
            circuit.push_back(u);
            st.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}

int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int t;
    cin >> t;

    if (t == 1) {
        cin >> n;
        a.assign(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];

        if (!isConnected()) { cout << 0 << "\n"; return 0; }

        int oddCount = 0;
        for (int i = 1; i <= n; i++) {
            int deg = 0;
            for (int j = 1; j <= n; j++) deg += a[i][j];
            if (deg % 2 != 0) oddCount++;
        }

        if (oddCount == 0) cout << 1 << "\n";
        else if (oddCount == 2) cout << 2 << "\n";
        else cout << 0 << "\n";
    } else {
        int u;
        cin >> n >> u;
        a.assign(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];

        vector<int> circuit = hierholzer(u);
        for (int i = 0; i < (int)circuit.size(); i++) {
            if (i > 0) cout << " ";
            cout << circuit[i];
        }
        cout << "\n";
    }
    return 0;
}
