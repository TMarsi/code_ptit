#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101],degIn[101],degOut[101],b[101][101];
pair<int,int> edges[101];
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	int t;cin >> t;
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v;cin >> u >> v;
		degOut[u]++;
		degIn[v]++;
		a[u][v] = 1;
	}
	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << degIn[i] << " " << degOut[i] << "\n";
		}
	} else {
		m = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(a[i][j]) {
					m++;
					edges[m] = {i,j};
				}
			}
		}
		cout << n << " " << m << "\n";
		for(int e = 1;e <= m;e++){
			int u = edges[e].first;
			int v = edges[e].second;
			b[v][e] = -1;
			b[u][e] = 1;
		}

		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cout << b[i][j] << " ";
			}
			cout << "\n";
		}
	}


	return 0;
}
