#include <bits/stdc++.h>
using namespace std;

int n, startV;
int a[105][105];
bool visited[105];
int path[105];
int cycleCount;

void backtrack(int u, int depth) {
  if (depth == n) {
    if (a[u][startV]) {
      for (int i = 0; i < n; i++) {
        if (i > 0)
          cout << " ";
        cout << path[i];
      }
      cout << " " << startV << "\n";
      cycleCount++;
    }
    return;
  }
  for (int v = 1; v <= n; v++) {
    if (a[u][v] && !visited[v]) {
      visited[v] = true;
      path[depth] = v;
      backtrack(v, depth + 1);
      visited[v] = false;
    }
  }
}

int main() {
  freopen("CT.INP", "r", stdin);
  freopen("CT.OUT", "w", stdout);

  cin >> n >> startV;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];

  visited[startV] = true;
  path[0] = startV;

  backtrack(startV, 1);

  cout << cycleCount << "\n";
  if (cycleCount == 0) {
  }
  return 0;
}

// cách 2 nhanh hơn k
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 105;
// int n, startV;
// bitset<MAXN> adj[MAXN];
// int path[MAXN];
// int cycleCount;

// void backtrack(int u, int depth, bitset<MAXN>& visited) {
//     if (depth == n) {
//         if (adj[u][startV]) {
//             for (int i = 0; i < n; i++) {
//                 if (i > 0) cout << " ";
//                 cout << path[i];
//             }
//             cout << " " << startV << "\n";
//             cycleCount++;
//         }
//         return;
//     }

//     bitset<MAXN> candidates = adj[u] & ~visited;
//     for (int v = candidates._Find_first(); v < MAXN; v =
//     candidates._Find_next(v)) {
//         visited.set(v);
//         path[depth] = v;
//         backtrack(v, depth + 1, visited);
//         visited.reset(v);
//     }
// }

// int main() {
//     freopen("CT.INP", "r", stdin);
//     freopen("CT.OUT", "w", stdout);
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n >> startV;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             int x; cin >> x;
//             if (x) adj[i].set(j);
//         }
//     }

//     bitset<MAXN> visited;
//     visited.set(startV);
//     path[0] = startV;

//     backtrack(startV, 1, visited);

//     cout << cycleCount << "\n";
//     return 0;
// }