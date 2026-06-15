#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101],deg[101],b[101][101];
pair<int,int> edges[101];

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
		edges[i] = {u,v};
	}
	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << deg[i] << " ";
		}
	} else{
		for(int k = 1;k <= m;k++){
			int u = edges[k].first;
			int v = edges[k].second;
			b[u][k] = 1;
			b[v][k] = 1;
		}
		cout << n << " " << m << "\n";
		for(int i = 1;i <= n;i++){
			for(int k = 1;k <= m;k++){
				cout << b[i][k] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
