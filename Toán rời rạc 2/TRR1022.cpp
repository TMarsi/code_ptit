#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101],degIn[101],degOut[101],b[101][101];
pair<int,int> edges[101];
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	m = 0;
	int t;cin >> t;
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v,w;cin >> u >> v >> w;
		degIn[v]++;
		degOut[u]++;
		a[u][v] = w;
	}

	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << degIn[i] << " " << degOut[i] << "\n";
		}
	} else {
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) a[i][j] = 0;
				if(a[i][j] == 0 && i != j) a[i][j] = 10000;
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
