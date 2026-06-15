#include<bits/stdc++.h>
using namespace std;

#define INF 10000

int n, s, t,c[101][101];
int path[101],a[101];
bool check[101];

int main(){
	freopen("DN.INP","r",stdin);
	freopen("DN.OUT","w",stdout);
	cin >> n >> s >> t;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) cin >> c[i][j];
	}
	for(int i = 1;i <= n;i++){
		a[i] = INF;
		path[i] = -1;
	}
	a[s] = 0; 

	for(int i = 1;i < n;i++){
		int u = -1;
		for(int j = 1;j <= n;j++){
			if(!check[j] && (u == -1 || a[j] < a[u] )) u = j;

		}
		if(u == -1 || a[u] == INF) break;

		check[u] = true;
		for(int j = 1;j <= n;j++){
			if(!check[j]  && (a[u] + c[u][j] < a[j])){
				a[j] = a[u] + c[u][j];
				path[j] = u;
			}
		}
	}
	
	if(a[t] == INF){
		cout << 0 << "\n";
	} else {
        cout << a[t] << "\n";
        vector<int> pat;
        for (int x = t; x != -1; x = path[x]) pat.push_back(x);
        reverse(pat.begin(), pat.end());
        for (int i = 0; i < (int)pat.size(); i++)
            cout << pat[i] << (i + 1 < (int)pat.size() ? " " : "\n");
    }
    return 0;

}
