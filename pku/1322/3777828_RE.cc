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
	
		if (1 == (n - m) % 2 || m > c || m > n)
		{
			printf("0.000\n");
			continue;
		}
		int j;
		int curr = 0, before = 1;
		//memset(f, 0, sizeof(f));
		for (j = 0; j <= n; j ++)	f[1][j] = f[0][j] = 0;
		f[0][0] = 1, f[1][1] = 1;
		
		while (n --)
		{
			f[curr][0] = f[before][1] * 1 / c;
			for (j = 1; j  < c; j ++)
			{
				f[curr][j] = f[before][j - 1] * (c - j + 1) / c + f[before][j + 1] * (j + 1) / c;
			}
			f[curr][c] = f[before][c - 1] * 1 / c;
			curr = 1 - curr;			
			before = 1 - curr;
		}
		printf("%.3lf\n", f[curr][m]);
	}	
	return 0;
}