


#include <iostream>

using namespace std;


template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR (i, 0, b)
#define FORD(i, a, b)	for (int i = (int)a; i >= (int)b; --i)


int g[200][200], ET, n;
int queue[20000], vis[200], vis2[200][200];

void input(){
	scanf("%d%d", &n, &ET);
	memset(g, 0, sizeof(g));
	int sta, end;
	while (EOF != scanf("%d %d", &sta, &end))
	{
		g[sta][end] = 1;
	}
}

bool dfs(int sta, int end, int m){
	//printf("<%d %d %d>\n", sta, end, m);
	if (vis2[sta][end])	return false;
	if (g[sta][end])	return true;
	REP (i, n)
	{
		if (m == sta || m == end ||m == i)	continue;
		if (g[sta][i] && !vis2[sta][i])
		{
			vis2[sta][i] = 1;
			return dfs(i, end, m);
			vis2[sta][i] = 0;
		}
	}
}


void solve(){
	int head, tail;
	memset(vis, 0, sizeof(vis));
	head = tail = 0;
	queue[tail++] = ET;
	vis[ET] = 1;

	while (head < tail)
	{
		int tmp = queue[head++];

		REP (i, n)
		{
			if (g[i][tmp] && !vis[i])
			{
				//printf("[%d %d]\n", tmp, i);
				queue[tail++] = i;
				vis[i] = 1;
				memset(vis2, 0, sizeof(vis2));
				if (!dfs(0, ET, i))
				{
					printf("Put guards in room %d.\n", i);
					return;
				}
			}	

		}
	}
}


int main(){
	input();
	solve();
	return 0;

}
