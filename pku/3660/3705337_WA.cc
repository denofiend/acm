//

#include <iostream>
#define MAXN 110
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i ] << ' ' ;		cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}


int n, m;
bool conform[MAXN];

void cal(int *in, int g[MAXN][MAXN]){
	int i;
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
		
		if (!conform[pos])	conform[pos] = true;
		in[pos] = -1;
		for (i = 1; i <= n; i ++)
		{
			if (g[pos][i] && i != pos)
			{
				g[pos][i] = 0;
				in[i] --;
			}
		}
	}
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
		memset(conform, 0, sizeof(conform));

		int i, j, sta, end;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d\n", &end, &sta);
			//printf("[%d %d]\n", end, sta);
			if (0 == g[sta][end])
			{
				g[sta][end] = 1;
				inDegree[end] ++;
			}
			if (0 == g1[end][sta])
			{
				g1[end][sta] = 1;
				inDegree1[sta] ++;
			}
		}
		if (1 == n)
		{
			printf("1\n");
			continue;
		}
		//out(g, n + 1, n + 1);
		//out(inDegree, n + 1);
		//out(g1, n + 1, n + 1);
		//out(inDegree1, n +1);
		cal(inDegree, g);

		cal(inDegree1, g1);
		
		int ret = 0;
		for (i = 1; i <= n; i ++)
			if (conform[i])	ret++;
		//out(conform, n + 1);
		printf("%d\n", ret);

	}
	return 0;
}