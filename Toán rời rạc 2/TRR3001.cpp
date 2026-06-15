#include <bits/stdc++.h>
using namespace std;

int n,u,a[101][101],deg[101];
bool vs[101];
vector<int> ans;

void DFS(int x){
	vs[x] = true;
	for(int i = 1;i <= n;i++){
		if(a[x][i] == 1 && !vs[i]){
			DFS(i);
		}
	}
}

void find(int x){
	for(int i = 1;i <= n;i++){
		if(a[x][i] == 1){
			a[x][i] = 0;
			a[i][x] = 0;
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
			for(int j = 1;j <= n;j++) {
				cin >> a[i][j];
				if(a[i][j]) deg[i]++;
			}
		}
		DFS(1);
	    bool connected = true;
	    for(int i = 1;i <= n;i++){
	        if(!vs[i]){ connected = false; break; }
	    }

	    int cnt = 0;
	    for(int i = 1;i <= n;i++){
	        if(deg[i] % 2 != 0) cnt++;
	    }

	    if(!connected) cout << 0 << "\n";
	    else if(cnt == 0) cout << 1 << "\n";
	    else if(cnt == 2) cout << 2 << "\n";
	    else cout << 0 << "\n";
	} else {
		cin >> n >> u;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cin >> a[i][j];
			}
		}
		find(u);
		reverse(ans.begin(),ans.end());
		for(int i = 0;i < (int)ans.size();i++){
			cout << ans[i] << (i < (int)ans.size() - 1 ? " " : "\n");
		}

	}

}
