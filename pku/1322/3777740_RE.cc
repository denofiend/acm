//

#include <iostream>
#define MAXN 101000
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i++)	out(x[i], m);	cout << endl;	}

double f[2][MAXN];

int main(){
	int c, n, m;
	while (EOF != scanf("%d", &c))
	{
		if (0 == c)	break;
		scanf("%d %d", &n, &m);
	
		if (!(0 == n % 2 && 0 == m % 2) || (1 == n % 2 && 1 == m % 2) || m > c || m > n)
		{
			printf("0.000\n");
			continue;
		}
		int i, j;
		f[0][0] = 1, f[1][1] = 1;
		for (i = 1; i <= n; i ++)	f[0][i] = 0;
		int curr = 0, before = 1;
		while (n --)
		{
			f[curr][0] = f[before][1] * 1 / c;
			for (j = 1; j  <= c; j ++)
			{
				f[curr][j] = f[before][j - 1] * (c - j + 1) / c + f[before][j + 1] * (j + 1) / c;
			}
			//out(f, 2, m + 1);
			curr = 1 - curr;			
			before = 1 - curr;
			//printf("[%d %d]\n", curr, before);	
		}
		//printf("curr = %d\n", curr);
		//out(f, 2, 100);
		printf("%.3lf\n", f[curr][m]);
	}	
	return 0;
}