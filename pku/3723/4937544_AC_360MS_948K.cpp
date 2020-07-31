//


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " =  " << x << endl)
#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for (int i = (int)a; i >= (int)b; --i)
#define MAXN 50010
#define MAXV 20010

int fa[MAXV], rank[MAXV];
int n, m, r;

struct Edge{
	int u, v, val;
};
Edge nd[MAXN];

void input(){
	scanf("%d%d%d", &m, &n, &r);
		
	REP (i, r)
	{
		scanf("%d%d%d", &nd[i].u, &nd[i].v, &nd[i].val);
		nd[i].v += m;
	}
	//out(g, n, m);
}



bool cmp(const Edge &a, const Edge &b){
	return a.val > b.val;
}

int findset(int x){
	if (x != fa[x])
	{
		fa[x] = findset(fa[x]);
	}
	return fa[x];
}

void link(int x, int y){
	if (rank[x] > rank[y])
	{
		fa[y] = x;
	}
	else
	{
		fa[x] = y;
		if (rank[x] == rank[y])	rank[y]++;
	}
}


void solve(){
	int ans = (n+m)*10000, ret = 0;
	sort(nd, nd+r, cmp);
	//REP (i, n+m)	printf("[%d %d %d]\n", nd[i].u, nd[i].v, nd[i].val);
	REP (i, n+m)	fa[i] = i, rank[i] = 0;
	REP (i, r)
	{
		int u = findset(nd[i].u);
		int v = findset(nd[i].v);
		if (u != v)
		{
			ret += nd[i].val;
			link(u, v);
		}
	}
	printf("%d\n", ans - ret);
}


int main(){
	int t;
	scanf("%d", &t);
	while (t--)
	{
		input();
		solve();

	}
	return 0;
}

