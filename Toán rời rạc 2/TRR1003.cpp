#include<bits/stdc++.h>
using namespace std;

int n,a[101][101],deg[101],b[101][101];
pair<int,int> edges[101];

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	int t;cin >> t;
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
			if(a[i][j]) deg[i]++;
		}
	}
	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << deg[i] << " ";
		}
	} else {
		int m = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[i][j]) {
					m++;
					edges[m] = {i,j};
				}
			}
		}
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
