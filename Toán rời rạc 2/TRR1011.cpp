#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101],deg[101];

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	int t;cin >> t;
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v,w;cin >> u >> v >> w;
		deg[u]++;
		deg[v]++;
		a[u][v] = w;
		a[v][u] = w;
	}
	if(t == 1){
		for(int i = 1;i <= n;i++) cout << deg[i] << " ";
	} else {
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) a[i][j] = 0;
				if(!a[i][j] && i != j) a[i][j] = 10000;
			}
		}
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
