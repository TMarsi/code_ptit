#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101],degIn[101],degOut[101],b[101][101];
pair<int,int> edges[101];
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	m = 0;
	int t;cin >> t;
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(i != j && a[i][j] != 0 && a[i][j] != 10000){
				degIn[j]++;
				degOut[i]++;
			}
		}
	}
	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << degIn[i] << " " <<degOut[i] << "\n";
		}
	} else {
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(a[i][j] != 0 && a[i][j] != 10000 && i != j) m++;
			}
		}
		cout << n << " " << m << "\n";
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= n;j++){
				if(a[i][j] != 0 && a[i][j] != 10000 && i != j) cout << i << " "  <<  j << " " << a[i][j] << "\n";
			}
		}
	}
	return 0;
}
