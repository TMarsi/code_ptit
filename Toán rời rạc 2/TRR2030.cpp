#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;

int countComponents(int skipU, int skipV) {
  vector<bool> vis(n + 1, false);
  int components = 0;

  for (int start = 1; start <= n; start++) {
    if (vis[start])
      continue;
    components++;

    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v = 1; v <= n; v++) {
        if (!vis[v] && a[u][v]) {
          if ((u == skipU && v == skipV) || (u == skipV && v == skipU))
            continue;
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
  return components;
}

int main() {
  freopen("TK.INP", "r", stdin);
  freopen("TK.OUT", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  a.assign(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];
  int original = countComponents(-1, -1);

  vector<pair<int, int>> bridges;
  for (int u = 1; u <= n; u++) {
    for (int v = u + 1; v <= n; v++) {
      if (a[u][v]) {
        if (countComponents(u, v) > original) {
          bridges.push_back({u, v});
        }
      }
    }
  }

  sort(bridges.begin(), bridges.end());

  cout << bridges.size() << "\n";
  for (auto &[u, v] : bridges)
    cout << u << " " << v << "\n";

  return 0;
}