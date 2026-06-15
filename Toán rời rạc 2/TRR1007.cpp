#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[101][101],deg[101];

int main(){
	freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
	int t;cin >> t;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int k;cin >> k;
		while(k--){
			int u;cin >> u;
			deg[u]++;
			a[u][i] = 1;
			a[i][u] = 1;
		}
	}
	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << deg[i] << " ";
		}
	} else {
		m = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[i][j]) m++;
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
}
