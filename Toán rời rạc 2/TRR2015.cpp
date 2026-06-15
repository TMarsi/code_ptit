#include<bits/stdc++.h>
using namespace std;

int n,a[101][101],c[101][101];
bool vs[101];
vector<int> edges;
int sodinhtham;

void DFS(int x){
	vs[x] = true;
	sodinhtham++;
	for(int i = 1;i <= n;i++){
		if(c[x][i] == 1 && !vs[i]){
			DFS(i);
		}
	}
}

bool thamdinh(){
	for(int i = 1;i <= n;i++) vs[i]= false;
	sodinhtham = 0;
	
	DFS(1);
	return (sodinhtham == n);
}

int main(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			c[i][j] = a[i][j];	
		} 
	}

	bool thuan = thamdinh();

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) c[i][j] = a[j][i];
	}
	
	bool nguoc = thamdinh();

	if(thuan && nguoc){
		cout << 1;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 0;
        }
    }

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i][j] == 1){
				c[i][j] = 1;
				c[j][i] = 1;
			}
		}
	}

	bool yeu = thamdinh();

	if(yeu) cout << 2;
	else cout << 0;

	return  0;
}
