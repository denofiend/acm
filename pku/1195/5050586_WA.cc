
// 1195(pku)
// 二维树状数组
//
//
#include <iostream>
#include <algorithm>
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)

// [1, MAXN)
#define MAXN 1025

int C[MAXN][MAXN];
int lev[200001];

int lowbit(int x){
	return x & (-x);
}


void add(int i, int j, int v){
	while (i < MAXN)
	{
		int j0 = j;
		while (j0 < MAXN)
		{
			C[i][j0] += v;
			j0 += lowbit(j0);
		}
		i += lowbit(i);
	}
}

int sum(int i, int j){
	int ret = 0;
	while (i)
	{
		int j0 = j;
		while (j0)
		{
			ret += C[i][j0];
			j0 -= lowbit(j0);
		}
		i -= lowbit(i);
	}
	return ret;
}



int main(){
	int command, A, L, R, B, T, X, Y, n;
	while (EOF != scanf("%d", &command))
	{
		if (3 == command)	break;	
		else if (0 == command)
		{
			scanf("%d", &n);
			FOR (i, 1, MAXN)
				FOR (j, 1, MAXN)
					C[i][j] = 0;
		} 
		else if (1 == command)
		{
			scanf("%d %d %d", &X, &Y, &A);
			add(X+1, Y+1, A);
		}
		else if (2 == command)
		{
			scanf("%d %d %d %d", &L, &B, &R, &T);
			printf("%d\n", sum(R+1, T+1) - sum(L, B));
		}
	}
	return 0;
}
