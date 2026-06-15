#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101],degIn[101],degOut[101];
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);

	int t;cin >> t;
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j]){
				degOut[i]++;
				degIn[j]++;
			}
		}
	}

	if(t == 1){
		for(int i = 1;i <= n;i++){
			cout << degIn[i] << " " << degOut[i] << "\n";
		}
	} else {
		cout << n << "\n";
		for(int i = 1;i <= n;i++){
			cout << degOut[i] << " ";
			for(int j = 1;j <= n;j++){
				if(a[i][j]) cout << j << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}
