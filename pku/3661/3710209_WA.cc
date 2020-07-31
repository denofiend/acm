//


#include <iostream>
#define MAXN 100001
#define MAXX 501
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}

int f[MAXN][MAXX];
int dis[MAXN];

int main(){
	int n, m;
	while (EOF != scanf("%d %d", &n, &m))
	{
		int i, j, k;
		for (i = 1; i <= n; i++)	scanf("%d", &dis[i]);

		//memset(f, 0, sizeof(f));

		for (i = 0; i <= n; i ++)	f[i][0] = f[0][i] = 0;
		int ans = 0;
		for (i = 1; i <= n; i ++)
		{
			f[i][0] = f[i - 1][0];
			for (j = i - 1, k = 1; i - j <= m && j >= 0; j --, k ++)
			{
				f[i][0] = max(f[i][0], f[j][k]);
			}
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
