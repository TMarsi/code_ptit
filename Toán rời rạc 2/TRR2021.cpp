#include<bits/stdc++.h>
using namespace std;

int n,a[101][101];
bool vs[101];

void DFS(int x){
	vs[x] = true;
	for(int i = 1;i <= n;i++){
		if(a[x][i] == 1 && !vs[i]) {
			DFS(i);
		}
	}
}


int main(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);

	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}
	
	vector<int> ans;
	for(int v = 1;v <= n;v++){
		memset(vs,false,sizeof(vs));
		vs[v] = true;
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(a[v][i] == 1 && !vs[i]){
				DFS(i);
				cnt++;
			}
		}
		if(cnt >= 2) ans.push_back(v); 
	}
	cout << ans.size() << "\n";
	if(!ans.empty()){
		for(int i = 0;i < (int)ans.size();i++){
			cout << ans[i] << (i < (int)ans.size() - 1 ? " " : "\n");
		}	
	}
	

}
