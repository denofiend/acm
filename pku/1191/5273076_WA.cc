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
#define Inf 0xfffffff

int f[MAXN*2][MAXN][MAXN][MAXN][MAXN];
int sum[MAXN][MAXN];
int n;

int get(int x0, int y0, int x1, int y1){
	int ret = sum[x1][y1];
	if (x0)	ret -= sum[x0-1][y1];
	if (y0 ) ret -= sum[x1][y0-1];
	if (x0 && y0)	ret += sum[x0-1][y0-1];
	return ret;
}

int rec(int n, int i0, int j0, int i1, int j1){
	if (Inf != f[n][i0][j0][i1][j1])	return f[n][i0][j0][i1][j1];

	//
	if (0 == n)
	{
		return f[n][i0][j0][i1][j1] = get(i0, j0, i1, j1) * get(i0, j0, i1, j1);
	}

	FOR (x, i0, i1)
	{
		int xx = get(i0, j0, x, j1) * get(i0, j0, x, j1);
		int xxx = rec(n-1, x+1, j0, i1, j1);
		f[n][i0][j0][i1][j1] = min(xx+xxx, f[n][i0][j0][i1][j1]);

		xx = get(x+1, j0, i1, j1) * get(x+1, j0, i1, j1);
		xxx = rec(n-1, i0, j0, x, j1);
		f[n][i0][j0][i1][j1] = min(xx+xxx, f[n][i0][j0][i1][j1]);
	}

	//
	FOR (y, j0, j1)
	{
		int yy = get(i0, j0, i1, y) * get(i0, j0, i1, y);
		int yyy = rec(n-1, i0, y+1, i1, j1);
		f[n][i0][j0][i1][j1] = min(yy+yyy, f[n][i0][j0][i1][j1]);

		yy = get(i0, y+1, i1, j1) * get(i0, y+1, i1, j1);
		yyy = rec(n-1, i0, j0, i1, y);
		f[n][i0][j0][i1][j1] = min(yy+yyy, f[n][i0][j0][i1][j1]);
	}
	return f[n][i0][j0][i1][j1];
}

int main(){
	while (EOF != scanf("%d", &n))
	{
		REP (i, 8)
			REP (j, 8)
				sum[i][j] = 0;
		REP (i, 8)
			REP (j, 8)
			{
				scanf("%d", &sum[i][j]);
				if (i)	sum[i][j] += sum[i-1][j];
				if (j)	sum[i][j] += sum[i][j-1];
				if (i && j)	sum[i][j] -= sum[i-1][j-1];
			}
		//out(sum, 8, 8);
		REP (k, n)
			REP (i0, 8)
				REP (j0, 8)
					REP (i1, 8)
						REP (j1, 8)
							f[k][i0][j0][i1][j1] = Inf;
		double s = sum[7][7] / n;
		s *= s;

		printf("%.3lf\n", sqrt( rec(n-1, 0, 0, 7, 7) * 1.0 / n - s));
	}
	return 0;
}
