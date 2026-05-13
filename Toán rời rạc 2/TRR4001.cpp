#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<bool> visited;
vector<pair<int, int>> tree_edges;

void dfsRec(int u) {
  visited[u] = true;
  for (int v = 1; v <= n; v++) {
    if (a[u][v] && !visited[v]) {
      tree_edges.push_back({min(u, v), max(u, v)});
      dfsRec(v);
    }
  }
}

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 1; v <= n; v++) {
      if (a[u][v] && !visited[v]) {
        visited[v] = true;
        tree_edges.push_back({min(u, v), max(u, v)});
        q.push(v);
      }
    }
  }
}

int main() {
  freopen("CK.INP", "r", stdin);
  freopen("CK.OUT", "w", stdout);

  int t, s;
  cin >> t >> n >> s;

  a.assign(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];

  visited.assign(n + 1, false);

  if (t == 1)
    dfsRec(s);
  else
    bfs(s);

  bool isSpanning = true;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      isSpanning = false;
      break;
    }
  }

  if (!isSpanning) {
    cout << 0 << "\n";
  } else {
    cout << (int)tree_edges.size() << "\n";
    for (auto &e : tree_edges)
      cout << e.first << " " << e.second << "\n";
  }

  return 0;
}