#include<bits/stdc++.h>
using namespace std;

int n,m,t,degIn[101],degOut[101],a[101][101],b[101][1001];


int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	cin >> t >> n >> m;

	if(t == 1){
		for(int i = 1;i <= m;i++){
			int u,v;cin >> u >> v;
			degOut[u]++;
			degIn[v]++;
		}
		for(int i = 1 ;i<= n;i++){
			cout << degIn[i] << " " << degOut[i] << '\n'; 
		}
	} else {
		for(int i = 1;i <= m;i++){
			int u,v;cin >> u >> v;
			a[u][v] = 1;
		}
		cout << n << "\n";
		for(int i = 1;i <= n;i++){
			int k = 0;
			for(int j = 1;j <= n;j++){
				if(a[i][j]) k++;
			}
			cout << k;
			for(int j = 1;j <= n;j++){
				if(a[i][j]) cout << " " << j;
			}
			cout << "\n";
		}
	}
	return 0;
}
