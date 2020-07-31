//

#include <iostream>
#define MAXN 110
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i ] << ' ' ;		cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}



int g[MAXN][MAXN];
int inDegree[MAXN];

int main(){
	int n, m;
	while (EOF != scanf("%d %d", &n, &m))
	{
		memset(g, 0, sizeof(g));
		memset(inDegree, 0, sizeof(inDegree));
		int i, j, sta, end;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d\n", &end, &sta);
			g[sta][end] = 1;
			inDegree[end] ++;
		}
		
		int ans = 0;
		while (1)
		{
			int num = 0, pos;
			for (i = 1; i <= n; i ++)
			{
				if (0 == inDegree[i])
				{
					num++;
					pos = i;
				}
			}
			//printf("[%d %d]\n", num, pos);
			if (1 != num)	break;
			ans ++;
			inDegree[pos] = -1;
			for (j = 1; j <= n; j ++)
			{
				if (g[pos][j] && j != pos)
				{
					g[pos][j] = 0;
					inDegree[j] --;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}