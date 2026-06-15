#include<bits/stdc++.h>
using namespace std;

int n,m,c[101],sum = 0;
struct edge{
	int u,v,w;
};
vector<edge> edges;
vector<edge> kq;

int find(int x){
	if(c[x] != x) c[x] = find(c[x]);
	return c[x];
} 



int main(){
	freopen("CK.INP","r",stdin);
	freopen("CK.OUT","w",stdout);

	cin >> n >> m;
	edges.resize(m);
	for(int i = 0;i < m;i++){
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	stable_sort(edges.begin(),edges.end(),[](const edge &a, const edge &b) {return a.w < b.w;});
	for(int i = 1;i <= n;i++) c[i] = i;
	for(int i = 0; i < (int)edges.size(); i++){
    int ru = find(edges[i].u);
    int rv = find(edges[i].v);
    if(ru != rv){
        c[ru] = rv;
        sum += edges[i].w;
        kq.push_back(edges[i]);
    }
}
	if ((int)kq.size() < n - 1) {
        cout << 0;
    } else {
        cout << sum << "\n";
        for (auto &e : kq)
            cout << e.u << " " << e.v << " " << e.w << "\n";
    }
}
