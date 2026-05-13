#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("DT.INP", "r", stdin);
  freopen("DT.OUT", "w", stdout);

  int t, n;
  cin >> t >> n;

  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  if (t == 1) {
    for (int i = 1; i <= n; i++) {
      int deg_in = 0, deg_out = 0;
      for (int j = 1; j <= n; j++) {
        if (a[i][j] == 1)
          deg_out++;
        if (a[j][i] == 1)
          deg_in++;
      }
      cout << deg_in << " " << deg_out << "\n";
    }
  } else if (t == 2) {
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
      vector<int> adj;
      for (int j = 1; j <= n; j++) {
        if (a[i][j] == 1)
          adj.push_back(j);
      }
      cout << adj.size();
      for (int v : adj)
        cout << " " << v;
      cout << "\n";
    }
  }

  return 0;
}