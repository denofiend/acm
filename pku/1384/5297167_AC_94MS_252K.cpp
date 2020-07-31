///



#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;


template <class T> void out(T x, int n){	for(int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for(int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)
#define Inf 0x7fffff
#define MAXN 501
#define MAXV 1000001

int f[MAXV];
int val[MAXN], w[MAXN];
int v0, v1, V, n;

void init(){
	f[0] = 1;
	int V = 500;
	FOR (i, 1, V+1)
	{
		FORD (j, V, i)
		{
			f[j] += f[j-i];
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &v0, &v1);
		V = v1 - v0;
		scanf("%d", &n);
		REP (i, n)	scanf("%d %d", &val[i], &w[i]);
		REP (i, V+1)	f[i] = Inf;

		f[0] = 0;

		REP (i, n)
		{
			REP (j, V+1)
			{
				if (j >= w[i])
				{
					if (-1 == f[j] || f[j] > f[j-w[i]] + val[i])	f[j] = f[j-w[i]] + val[i];
				}
			}
		}
		//out(f, V+1);
		if (Inf == f[V])	printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", f[V]);
	}
	return 0;
}
