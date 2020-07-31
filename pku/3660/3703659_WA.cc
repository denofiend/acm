//

#include <iostream>
#define MAXN 110
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i ] << ' ' ;		cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}


int n, m;

int cal(int *in, int g[MAXN][MAXN]){
	int ans = 0, i, j;
	while (1)
	{
		int num = 0, pos;
		for (i = 1; i <= n; i ++)
		{
			if (0 == in[i])
			{
				num++;
				pos = i;
			}
		}
		//printf("[%d %d]\n", num, pos);
		if (1 != num)	break;
		ans ++;
		in[pos] = -1;
		for (j = 1; j <= n; j ++)
		{
			if (g[pos][j] && j != pos)
			{
				g[pos][j] = 0;
				in[j] --;
			}
		}
	}
	return ans;
}
int main(){
	int g[MAXN][MAXN], g1[MAXN][MAXN];
	int inDegree[MAXN], inDegree1[MAXN];
	while (EOF != scanf("%d %d", &n, &m))
	{
		memset(g, 0, sizeof(g));
		memset(g1, 0, sizeof(g1));
		memset(inDegree, 0, sizeof(inDegree));
		memset(inDegree1, 0, sizeof(inDegree1));
		int i, j, sta, end;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d\n", &end, &sta);
			g[sta][end] = 1;
			inDegree[end] ++;
			g1[end][sta] = 1;
			inDegree1[sta] ++;
		}
		
		//out(g, n + 1, n + 1);
		//out(inDegree, n + 1);
		//out(g1, n + 1, n + 1);
		//out(inDegree1, n +1);
		int ret = cal(inDegree, g);
		int ret1 = cal(inDegree1, g1);
		
		//printf("[%d %d]\n", ret, ret1);
		printf("%d\n", max(ret, ret1));
	}
	return 0;
}