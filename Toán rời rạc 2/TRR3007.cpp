#include <iostream>
using namespace std;

int n, start, count, a[105][105], path[105];
bool vs[105];

void backtrack(int u, int depth) {
    if (depth == n) {
        if (a[u][start]) {
            for (int i = 0; i < n; i++) cout << path[i] << " ";
            cout << start << "\n";
            count++;
        }
        return;
    }
    for (int v = 1; v <= n; v++) {
        if (a[u][v] && !vs[v]) {
            vs[v] = true; 
            path[depth] = v;
            backtrack(v, depth + 1);
            vs[v] = false;
        }
    }
}

int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];

    vs[start] = true; 
    path[0] = start;
    backtrack(start, 1);
    
    cout << count;
    return 0;
}
