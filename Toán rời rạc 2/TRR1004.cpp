#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101],deg[101];

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	int t;cin >> t;
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v;cin >> u >> v;
		deg[u]++;
		deg[v]++;
		a[u][v] = 1;
		a[v][u] = 1;
	}
	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << deg[i] << " ";
		}
	} else {
		cout << n << "\n";
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}
