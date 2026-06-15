#include<bits/stdc++.h>
using namespace std;

int n,t,degIn[101],degOut[101],a[101][101],b[101][101];
vector<int> adj[101];

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	cin >> t >> n;
	for(int i = 1;i <= n;i++){
		int k;cin >> k;
		degOut[i] = k;
		int v;
		for(int j = 1;j <= k;j++){
			cin >> v;
			adj[i].push_back(v);
			degIn[v]++;
			a[i][v] = 1;
		}
	}
	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << degIn[i] << " " << degOut[i] << "\n";
		}
	} else {
		int m = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(a[i][j]) m++;
			}
		}
		int e = 1;
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= m;j++){
				if(a[i][j]){
					b[i][e] = 1;
					b[j][e] = -1;
					e++;
				}
			}
		}
		cout << n << " " << m << "\n";
		for(int i = 1;i <= n;i++){
			for(int k = 1;k <= m;k++){
				cout << b[i][k];
				if(k < m) cout << " ";
			}
			cout << "\n";
		}
	}
}
