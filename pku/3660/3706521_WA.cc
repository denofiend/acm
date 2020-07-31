//

#include <iostream>
#define MAXN 110
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i ] << ' ' ;		cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}


int n, m;
bool conform[MAXN];

void cal(int *vIn, int sort[MAXN][MAXN]){
	int i, flag = 0, top;

	for ( i = 1; i <= n; i ++ )
	{
		if ( 0 == vIn[i] )
		{
			flag ++;
			top = i;
		}
	}
	//printf("[%d %d]\n", flag, top);
	int tmp;
	/* TopoSort */
	while  (1 == flag)
	{
		tmp = top;
		conform[tmp] = true;
		flag = 0;
		for (i = 1; i <= n; i ++)
		{
			if  (tmp != i)
			{
				if (sort[tmp][i] )
				{
					vIn[ sort[tmp][i] ] --;
					if  (0 == vIn[ sort[tmp][i] ])
					{
						top = sort[tmp][i];
						flag ++;
					}
				}
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
		memset(conform, false, sizeof(conform));

		int i, sta, end;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d\n", &end, &sta);
			//printf("[%d %d]\n", end, sta);
			if (0 == g[sta][end])
			{
				g[sta][end] = end;
				inDegree[end] ++;
			}
			if (0 == g1[end][sta])
			{
				g1[end][sta] = sta;
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