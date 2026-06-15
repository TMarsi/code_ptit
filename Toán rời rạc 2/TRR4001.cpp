#include<bits/stdc++.h>
using namespace std;

int n,s,a[101][101];
bool vs[101];

struct edges
{
	int u,v;
};
vector<edges> khung;
void DFS(int x){
	vs[x] = true;
	for(int i = 1;i <= n;i++){
		if(a[x][i] == 1 && !vs[i]) {
			khung.push_back({min(x,i),max(x,i)});
			DFS(i);
		}
	}
}

void BFS(int start){
	queue<int> q;
	vs[start] = true;
	q.push(start);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 1;i <= n;i++){
			if(a[x][i] == 1 && !vs[i]){
				vs[i] = true;
				khung.push_back({min(x,i),max(x,i)});
				q.push(i);
			}
		}
	}
}

int main(){

	freopen("CK.INP","r",stdin);
	freopen("CK.OUT","w",stdout);

	int t;cin >> t;
	cin >> n >> s ;
	for(int i = 1;i <= n ;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}

	for(int i = 1;i <= n;i++) vs[i] = false;
	if(t == 1){
		DFS(s);

	} else BFS(s);

	int count = 0;
    for (int i = 1; i <= n; i++) if (vs[i]) count++;

	if(count == n && khung.size() == (n - 1)){
		cout << n - 1 << "\n";
		for (int e = 0;e < (int)khung.size();e++) {
            cout << khung[e].u << " " << khung[e].v << "\n";
        }
	} else {
		cout << 0 << "\n";
	}
	return 0;
}
