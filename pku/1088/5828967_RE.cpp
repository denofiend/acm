#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;


template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)

#define MAXN 110

int g[MAXN][MAXN];
int n, m;
int f[MAXN][MAXN];

int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool inMaze(const int &x, const int &y){
	return 0 <= x && x < n && 0 <= y && y < m;
}


int rec(int x, int y){
	if (f[x][y] != 0)	return f[x][y];
	int x0, y0;
	REP (i, 4)
	{
		x0 = x + dir[i][0];
		y0 = y + dir[i][1];
		if (!inMaze(x0, y0))	continue;
		if (g[x0][y0] >= g[x][y])
			f[x][y] = max(f[x][y], rec(x0, y0) + 1);
	}
	return f[x][y];
}

int main(){
	while (EOF != scanf("%d %d", &n, &m))
	{
		REP (i, n)
			REP (j, m)
				scanf("%d", &g[i][j]);

		REP (i, n)
			REP (j, m)
				f[i][j] = 0;
		int ans = 0;
		REP (i, n)
			REP (j, m)
			{
				if (ans < rec(i, j))	ans = rec(i, j);
			}
		printf("%d\n", ans+1);
		//out(f, n, m);
	}
	return 0;
}
