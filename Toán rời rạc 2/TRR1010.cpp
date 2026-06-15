#include<bits/stdc++.h>
using namespace std;

int n,a[101][101],deg[101];

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	int t;cin >> t;
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
			if(i != j &&a[i][j] != 0 && a[i][j] != 10000) deg[i]++;
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
				if(i != j &&a[i][j] != 0 && a[i][j] != 10000) {
					m++;

				}
			}
		}
		cout << n << " " << m <<"\n";
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(i != j &&a[i][j] != 0 && a[i][j] != 10000){
					cout << i << " " << j << " " << a[i][j] << "\n"; 
				}
			}
		}
	}
	return 0;
}
