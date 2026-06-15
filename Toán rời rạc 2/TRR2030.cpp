#include<bits/stdc++.h>
using namespace std;

int n,a[101][101];
bool vs[101];

void BFS(int start){
	queue<int> q;
	q.push(start);
	vs[start] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 1;i <= n;i++){
			if(a[x][i] == 1 && !vs[i]){
				q.push(i);
				vs[i] = true;
			}
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
	
	vector<pair<int,int>> luu;
	for(int u = 1;u <= n;u++){
		for(int v = u + 1;v <= n;v++){
			if(a[u][v] == 1){
				a[u][v] = 0;
				a[v][u] = 0;
				memset(vs,false,sizeof(vs));
				BFS(u);
				if(!vs[v]) luu.push_back({u,v});
				a[u][v] = 1;
				a[v][u] = 1;
			}
		}
	}
	cout << luu.size() << "\n";
	for(int i = 0;i < (int)luu.size();i++){
		cout << luu[i].first << " " << luu[i].second <<  "\n";
	}
}
