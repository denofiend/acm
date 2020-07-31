///


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)

int mm[10][10];
int ans[10][10];

int n = 6, m = 7;


int solve(){
	FOR (i, 1, n-1)
	{
		FOR (j, 1, m)
		{
			ans[i+1][j] = (mm[i][j] + ans[i][j] + ans[i-1][j] + ans[i][j-1] + ans[i][j+1]) % 2;
		}
	}

	FOR (j, 1, m)	if ((ans[5][j-1] + ans[5][j] + ans[5][j+1] + ans[4][j]) % 2 != mm[5][j])	return 0;

	return 1;
}


int main(){
	int t;
	scanf("%d", &t);
	FOR (tt, 1, t+1)
	{
		printf("PUZZLE #%d\n", tt);

		FOR (i, 1, n)
			FOR (j, 1, m)
				scanf("%d", &mm[i][j]);

		FOR (j, 1, m)	ans[1][j] = 0;
		while (1)
		{
			int i = 1;
			ans[1][1]++;
			while (2 == ans[1][i])
			{
				if (i == m)	break;
				ans[1][i+1]++;
				ans[1][i] = 0;
				i++;
			}
			if (i == m)	break;
			if (solve())
			{
				
				FOR (i, 1, n)
				{
					printf("%d", ans[i][1]);
					FOR (j, 2, m)
						printf(" %d", ans[i][j]);
					printf("\n");
				}
				break;
			}
		}
	}
	return 0;
}
