
// bai lỗi vì k dùng freopen chỉ cần sửa thành stdin stdout là đc
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  cin >> t >> n;

  vector<vector<int>> adj(n + 1);
  vector<int> deg(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    deg[i] = k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      adj[i].push_back(v);
    }
  }

  if (t == 1) {
    for (int i = 1; i <= n; i++) {
      if (i > 1)
        cout << " ";
      cout << deg[i];
    }
    cout << "\n";
  } else {
    set<pair<int, int>> edgeSet;
    for (int u = 1; u <= n; u++) {
      for (int v : adj[u]) {
        int a = min(u, v), b = max(u, v);
        if (a != b)
          edgeSet.insert({a, b});
      }
    }

    vector<pair<int, int>> edges(edgeSet.begin(), edgeSet.end());
    int m = edges.size();

    cout << n << " " << m << "\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        if (j > 0)
          cout << " ";
        int val = (edges[j].first == i || edges[j].second == i) ? 1 : 0;
        cout << val;
      }
      cout << "\n";
    }
  }

  return 0;
}