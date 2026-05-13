#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rank_;
    DSU(int n) : parent(n+1), rank_(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }
};

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    
    stable_sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    int totalWeight = 0;
    int edgesUsed = 0;
    vector<Edge> mstEdges;

    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            totalWeight += e.w;
            mstEdges.push_back(e);
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }

    if (edgesUsed < n - 1) {
        cout << 0 << "\n";
    } else {
        cout << totalWeight << "\n";
        for (auto& e : mstEdges)
            cout << e.u << " " << e.v << " " << e.w << "\n";
    }
    return 0;
}
