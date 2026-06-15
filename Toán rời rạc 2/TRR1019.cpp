#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101],degIn[101],degOut[101];
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	int t;cin >> t;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int k;cin >>k;
		degOut[i] = k;
		for(int j = 1;j <= k;j++){
			int u;cin >> u;
			a[i][u] = 1;
			degIn[u]++;
		}
	}
	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << degIn[i] << " " << degOut[i] << "\n";
		}
	}else{
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(a[i][j]) m++;
			}
		}
		cout << n << " " << m << "\n";
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= n;j++){
				if(a[i][j]) cout << i << " " << j <<"\n";
			}
		}
	}
	return 0;
}
