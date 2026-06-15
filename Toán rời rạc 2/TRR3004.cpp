#include<bits/stdc++.h>
using namespace std;

int n,u,a[101][101],degOut[101],degIn[101];
bool vs[101];
vector<int> ans;

void DFS(int x){
	vs[x] = true;
	for(int i = 1;i <= n;i++){
		if((a[x][i] == 1 || a[i][x] == 1) && !vs[i]){
			DFS(i);
		}
	}
}

void find(int x){
	for(int i = 1;i <= n;i++){
		if(a[x][i] == 1){
			a[x][i] = 0;
			find(i);
		}
	}
	ans.push_back(x);
}

int main(){
	freopen("CT.INP","r",stdin);
	freopen("CT.OUT","w",stdout);

	int t;cin >> t;
	if(t == 1){
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cin >> a[i][j];
				if(a[i][j]) {
					degOut[i]++;
					degIn[j]++;
				}
			}
		}

		DFS(1);
		bool ok = true;
		for(int i = 1;i <= n;i++){
			if(!vs[i]) {
				ok = false;
				break;
			}
		}
		int dau = 0,cuoi = 0,mid = 0;
		for(int i = 1;i <= n;i++){
			int diff = degOut[i] - degIn[i];
			if(diff == 1) dau++;
			else if(diff == -1) cuoi++;
			else if(diff != 0) mid++;

		}
		if(ok && dau == 0 && mid == 0 && cuoi == 0) cout << 1;
		else if(ok && dau == 1 && cuoi == 1 && mid == 0) cout << 2;
		else cout << 0;
	} else {
		cin >> n >> u;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cin >> a[i][j];
			}
		}
		find(u);
		reverse(ans.begin(),ans.end());
		for(int i = 0;i < (int) ans.size();i++){
			cout << ans[i] << (i < (int)ans.size() - 1 ? " " : "\n");
		}
	}
}
