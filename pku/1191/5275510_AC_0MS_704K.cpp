//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)
#define MAXN 10
#define Inf 0x7fffffff

int f[MAXN*2][MAXN][MAXN][MAXN][MAXN];
int sum[MAXN][MAXN];
int a[MAXN][MAXN];

int get(int x0, int y0, int x1, int y1){
	int ret = sum[x1][y1];
	if (x0)	ret -= sum[x0-1][y1];
	if (y0 ) ret -= sum[x1][y0-1];
	if (x0 && y0)	ret += sum[x0-1][y0-1];
	return ret;
}

int rec(int n, int i0, int j0, int i1, int j1){
	if (Inf != f[n][i0][j0][i1][j1])	return f[n][i0][j0][i1][j1];
	if (i0 == i1 && j0 == j1)	return f[n][i0][j0][i1][j1] = get(i0, j0, i1, j1) * get(i0, j0, i1, j1);
	//
	if (0 == n)
	{
		return f[n][i0][j0][i1][j1] = get(i0, j0, i1, j1) * get(i0, j0, i1, j1);
	}

	int cost = Inf;
	FOR (x, i0, i1)
	{
		int xx = get(i0, j0, x, j1) * get(i0, j0, x, j1);
		int xxx = rec(n-1, x+1, j0, i1, j1);
		cost = min(xx + xxx, cost);

		xx = get(x+1, j0, i1, j1) * get(x+1, j0, i1, j1);
		xxx = rec(n-1, i0, j0, x, j1);
		cost = min(xx + xxx, cost);
	}

	//
	FOR (y, j0, j1)
	{
		int yy = get(i0, j0, i1, y) * get(i0, j0, i1, y);
		int yyy = rec(n-1, i0, y+1, i1, j1);
		cost = min(yy + yyy, cost);

		yy = get(i0, y+1, i1, j1) * get(i0, y+1, i1, j1);
		yyy = rec(n-1, i0, j0, i1, y);
		cost = min(yy + yyy, cost);
	}
	return f[n][i0][j0][i1][j1] = cost;
}

int main(){
	int n;
	while (EOF != scanf("%d", &n))
	{
		REP (i, 8)
			REP (j, 8)
			{
				scanf("%d", &a[i][j]);
			}
		sum[0][0] = a[0][0];
		FOR (i, 1, 8)	sum[0][i] += sum[0][i-1] + a[0][i], sum[i][0] += sum[i-1][0] + a[i][0];
		FOR (i, 1, 8)
		{
			FOR (j, 1, 8)
			{
				sum[i][j] = a[i][j];
				sum[i][j] += sum[i-1][j];
				sum[i][j] += sum[i][j-1];
				sum[i][j] -= sum[i-1][j-1];
			}
		}
		REP (k, n)
			REP (i0, 8)
				REP (j0, 8)
					REP (i1, 8)
						REP (j1, 8)
							f[k][i0][j0][i1][j1] = Inf;
		double s = sum[7][7] / (double)n;
		s *= s;

		printf("%.3lf\n", sqrt( rec(n-1, 0, 0, 7, 7) / double(n) - s));
}
	return 0;
}
