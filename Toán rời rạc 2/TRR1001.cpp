#include<bits/stdc++.h>
using namespace std;

int n,a[101][101],deg[101];

int main(){
    freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t;cin >> t;
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}

	if(t == 1){
		for (int i = 1; i <= n; ++i)
		{
			for(int j = 1;j <= n;j++) if(a[i][j]) deg[i]++;
		}
		for(int i = 1;i <= n;i++) cout << deg[i] << " ";
	} else {
		int m = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[i][j]) m++;
			}
		}
		cout << n << " " << m << "\n";
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[i][j]) cout << i << " " << j << "\n";
			}
		}
	}
	return 0;
}
