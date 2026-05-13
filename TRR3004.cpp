#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;

void dfs_directed(int u, vector<bool>& vis) {
    vis[u] = true;
    for (int v = 1; v <= n; v++)
        if (a[u][v] && !vis[v])
            dfs_directed(v, vis);
}

void dfs_undirected(int u, vector<bool>& vis) {
    vis[u] = true;
    for (int v = 1; v <= n; v++)
        if ((a[u][v] || a[v][u]) && !vis[v])
            dfs_undirected(v, vis);
}

bool isStronglyConnected() {
    vector<bool> vis(n+1, false);
    dfs_directed(1, vis);
    for (int i = 1; i <= n; i++) if (!vis[i]) return false;
    
    fill(vis.begin(), vis.end(), false);
    vis[1] = true;
    stack<int> st;
    st.push(1);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v = 1; v <= n; v++)
            if (a[v][u] && !vis[v]) { vis[v] = true; st.push(v); }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) return false;
    return true;
}

bool isWeaklyConnected() {
    vector<bool> vis(n+1, false);
    dfs_undirected(1, vis);
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

        vector<int> indeg(n+1, 0), outdeg(n+1, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j]) { outdeg[i]++; indeg[j]++; }

        
        if (isStronglyConnected()) {
            bool euler = true;
            for (int i = 1; i <= n; i++)
                if (indeg[i] != outdeg[i]) { euler = false; break; }
            if (euler) { cout << 1 << "\n"; return 0; }
        }

        
        if (isWeaklyConnected()) {
            int cntOut = 0, cntIn = 0, cntBal = 0;
            for (int i = 1; i <= n; i++) {
                if (outdeg[i] == indeg[i] + 1) cntOut++;
                else if (indeg[i] == outdeg[i] + 1) cntIn++;
                else if (indeg[i] == outdeg[i]) cntBal++;
            }
            if (cntOut == 1 && cntIn == 1 && cntBal == n - 2) {
                cout << 2 << "\n"; return 0;
            }
        }

        cout << 0 << "\n";
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
