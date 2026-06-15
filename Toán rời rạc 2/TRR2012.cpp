#include<bits/stdc++.h>
using namespace std;

int n,a[101][101];
vector<int> edges;
bool vs[101];

void BFS(int start){
	queue<int> q;
	q.push(start);
	vs[start] = true;
	edges.push_back(start);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 1;i <= n;i++){
			if(a[x][i] == 1 && !vs[i]){
				vs[i] = true;
				q.push(i);
				edges.push_back(i);
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

	vector<vector<int>> luu;

	for(int i = 1;i <= n;i++){
		if(!vs[i]){
			edges.clear();
			BFS(i);
			sort(edges.begin(),edges.end());
			luu.push_back(edges);
		}
	}
	cout << luu.size() << "\n";
	for(int i = 0;i < (int)luu.size();i++){
		for(int j = 0;j < (int)luu[i].size();j++){
			cout << luu[i][j] << " ";
		}
		cout << "\n";
	}
}
