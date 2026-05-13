#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
  freopen("CK.INP", "r", stdin);
  freopen("CK.OUT", "w", stdout);

  int n, s;
  if (!(cin >> n >> s))
    return 0;

  vector<vector<int>> c(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
    }
  }

  vector<bool> inMST(n + 1, false);
  inMST[s] = true;
  int total_weight = 0;

  struct Edge {
    int u, v, w;
  };
  vector<Edge> mst_edges;

  for (int step = 1; step < n; ++step) {
    int min_w = INF;
    int best_u = -1, best_v = -1;
    for (int u = 1; u <= n; ++u) {
      if (inMST[u]) {
        for (int v = 1; v <= n; ++v) {
          if (!inMST[v] && c[u][v] < min_w) {
            min_w = c[u][v];
            best_u = u;
            best_v = v;
          }
        }
      }
    }

    if (best_u == -1 || min_w == INF) {
      cout << 0 << "\n";
      return 0;
    }

    inMST[best_v] = true;
    total_weight += min_w;

    int u_out = best_u;
    int v_out = best_v;
    if (u_out > v_out)
      swap(u_out, v_out);

    mst_edges.push_back({u_out, v_out, min_w});
  }

  cout << total_weight << "\n";
  for (const auto &edge : mst_edges) {
    cout << edge.u << " " << edge.v << " " << edge.w << "\n";
  }

  return 0;
}

// CÁCH 2
// #include <bits/stdc++.h>
// using namespace std;
// const int INF = 10000;
// int n, s, c[105][105];
// bool inMST[105];

// int main() {
//     freopen("CK.INP","r",stdin); freopen("CK.OUT","w",stdout);
//     cin >> n >> s;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++) cin >> c[i][j];

//     inMST[s] = true;
//     int total = 0;
//     vector<int> eu, ev, ew;

//     for (int step = 1; step < n; step++) {
//         int minW = INF, bu = -1, bv = -1;
//         for (int u = 1; u <= n; u++) if (inMST[u])
//             for (int v = 1; v <= n; v++)
//                 if (!inMST[v] && c[u][v] < minW)
//                     minW = c[u][v], bu = u, bv = v;

//         if (bu == -1) { cout << 0; return 0; }

//         inMST[bv] = true;
//         total += minW;
//         if (bu > bv) swap(bu, bv);
//         eu.push_back(bu); ev.push_back(bv); ew.push_back(minW);
//     }

//     cout << total << "\n";
//     for (int i = 0; i < (int)eu.size(); i++)
//         cout << eu[i] << " " << ev[i] << " " << ew[i] << "\n";
//     return 0;
// }