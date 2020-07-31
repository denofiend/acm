//


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)
#define MAXN 110
#define Inf 0xffff

char s[MAXN];
int f[MAXN][MAXN];
int n;


void output(int s0, int e0){
	if (s0 > e0)	return;
	if (s0 == e0)
	{
		if ('(' == s[s0] || ')' == s[s0])	printf("()");
		if ('[' == s[s0] || ']' == s[s0])	printf("[]");
		return;
	}	


	FOR (k, s0, e0)
	{
		if (f[s0][e0] == f[s0][k] + f[k+1][e0])
		{
			output(s0, k);
			output(k+1, e0);
			return;
		}
	}
	
	printf("%c", s[s0]);
	output(s0+1, e0-1);
	printf("%c", s[e0]);

}


int main(){
	while (EOF != scanf("%s", s))
	{
		n = strlen(s);
		REP (i, n)	f[i][i] = 1, f[i][i-1] = 0;

		FOR(s0, 1, n)
		{
			REP (i, n-s0)
			{
				int j = i+s0;
				//[i, j]
				//printf("[%d %d]\n", i, j);
				f[i][j] = Inf;
				if ('[' == s[i] && ']' == s[j])	f[i][j] = f[i+1][j-1];
				if ('(' == s[i] && ')' == s[j])	f[i][j] = f[i+1][j-1];
				if ('(' == s[i] || '[' == s[i])	f[i][j] = min(f[i][j], f[i+1][j]+1);
				if (')' == s[j] || ']' == s[j])	f[i][j] = min(f[i][j], f[i][j-1]+1);

				FOR (k, i, j)
					f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
				
			}
		}
		//out(f, n, n);
		//OUT(f[0][n-1]);
		output(0, n-1);
		printf("\n");
	}
	return 0;
}
