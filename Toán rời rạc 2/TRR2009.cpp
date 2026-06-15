#include<bits/stdc++.h>
using namespace std;

int n,a[101][101];
bool vs[101];
vector<int> edges;

void DFS(int x){
	vs[x] = true;
	edges.push_back(x);
	for(int i = 1;i <= n;i++){
		if(a[x][i] == 1 && !vs[i]){
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
	vector<vector<int>> luu;

	for(int i = 1;i <= n;i++){
		if(!vs[i]){
			edges.clear();
			DFS(i);
			sort(edges.begin(),edges.end());
			luu.push_back(edges);
			}
	}
	
	cout << luu.size() << "\n";

	for(int c = 0;c < (int)luu.size();c++){
		for(int i = 0;i < (int)luu[c].size();i++){
			cout << luu[c][i];
			if(i < (int)luu[c].size() - 1) cout << " ";
		}
		cout << "\n";
	}

}
