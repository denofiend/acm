// 
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;


template <class T> void out(T x, int n){	for(int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for(int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b) FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)
#define MAXN 110
#define MAXV 100001

double f[MAXN];

int num[MAXN];
int num0[MAXV];
double price[MAXV];
int n, m;

int main(){
	while (EOF != scanf("%d %d", &n, &m))
	{
		if (0 == n && 0 == m)	break;
		REP (i, n)	scanf("%d", &num[i]);
		REP (i, m)	scanf("%d %lf", &num0[i], &price[i]);

		REP (i, m+1)	f[i] = 1e30;

		f[0] = 0;

		FOR (i,	1, m+1)
		{
			FORD (j, n, 1)
			{
				if (1e30 != f[j-1])
				{
					if (num0[i-1] == num[j-1])
						f[j] = min(f[j], f[j-1] + price[i-1]);
				}
			}
		}	
		//out(f, m+1, n+1);
		if (1e30 == f[n])	printf("Impossible\n");
		else printf("%.2lf\n", f[n]);
	}
	return 0;
}

