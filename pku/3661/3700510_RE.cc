//


#include <iostream>
#define MAXN 510

using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}

int f[MAXN][MAXN];
int dis[MAXN];

int main(){
	int n, m;	
	while (EOF != scanf("%d %d", &n, &m))
	{
		int i, j;
		for (i = 1; i <= n; i++)	scanf("%d", &dis[i]);

		//memset(f, 0, sizeof(f));

		for (i = 0; i <= n; i ++)	f[i][0] = f[0][i] = 0;
		int ans = 0;
		for (i = 1; i <= n; i ++)
		{
			f[i][0] = f[i - 1][1];
			for (j = 1; j <= m; j ++)
			{
				f[i][j] = max(f[i -  1][j - 1] + dis[i], f[i - 1][j + 1]);
			}
			if (ans < f[i][0])	ans = f[i][0];
		}
		//out(f, n + 1, m + 1);
		printf("%d\n", ans);
	}
	return 0;
}