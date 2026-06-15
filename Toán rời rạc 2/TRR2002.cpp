#include<bits/stdc++.h>
using namespace std;

int n,u,v,a[1001][1001];
bool vs[1001] ;
vector<int> edges;
int ok[1001];

void BFS(int start){
	queue<int> q;
	q.push(start);
	vs[start] = true;
	ok[start] = -1;

	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == v) return;

		for(int i = 1;i <= n;i++){
			if(a[x][i] == 1 && !vs[i]){
				vs[i] = true;
				ok[i] = x;
				q.push(i);
			}
		}
	}
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
		int count = 0;
		for(int k = 1;k <= n;k++) {if (k != u && k!= v && a[u][k] && a[k][v])  count ++;}
		cout << count;
	} else {
		BFS(u);
		if(vs[v]){
			for(int i = v;i != -1;i = ok[i]){
				edges.push_back(i);
			}
			reverse(edges.begin(),edges.end());
			for(int i = 0;i < (int)edges.size();i++){
				cout << edges[i];
				if(i != (int)edges.size() - 1) cout << " ";
			}
		} else {
			cout << 0;
		}
	}
}
