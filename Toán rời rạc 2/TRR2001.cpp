#include <bits/stdc++.h>
using namespace std;

int n,u,v,a[101][101];
bool vs[101];
vector<int> edges;
bool ok;
void DFS(int x){
	vs[x] = true;
	ok = false;
	edges.push_back(x);
	if(x == v){
		ok = true;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(a[x][i] == 1 && !vs[i]){
			DFS(i);
			if(ok) return;
		}
	}
	vs[x] = false;
	edges.pop_back();
}


int main(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
	int t;cin >> t;
	cin >> n >> u >> v;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}

	if(t == 1){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			cnt += a[u][i] * a[i][v];
		}
		cout << cnt << "\n";
	} else {
		DFS(u);
		if(ok){
			for(int i = 0;i < (int)edges.size();i++){
				cout << edges[i] << " ";
			}
		} else {
			cout << 0 ;
		}
	}
}
