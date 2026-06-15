#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int n, s, c[101][101];
bool MST[101];

int main() {
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];

    MST[s] = true;
    int sum = 0;
    vector<int> eu, ev, ew;

    for (int i = 1; i< n; i++) {
        int minW = INF, bu = -1, bv = -1;
        for (int j = 1; j <= n; j++) if (MST[j])
            for (int k = 1; k <= n; k++)
                if (!MST[k] && c[j][k] < minW)
                    minW = c[j][k], bu = j, bv = k;

        if (bu == -1) { cout << 0; return 0; }

        MST[bv] = true;
        sum += minW;
        if (bu > bv) swap(bu, bv);
        eu.push_back(bu); ev.push_back(bv); ew.push_back(minW);
    }

    cout << sum << "\n";
    for (int i = 0; i < (int)eu.size(); i++)
        cout << eu[i] << " " << ev[i] << " " << ew[i] << "\n";
    return 0;
}
