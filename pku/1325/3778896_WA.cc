//

#include <iostream>
#define MAXN 110
using namespace std;

int g[MAXN][MAXN], visited[MAXN], match[MAXN];
int n, m, k;

void input(){
	int i, a, b, j;
	scanf("%d %d", &m, &k);
	memset(g, 0, sizeof(g));
	for (j = 0; j < k; j ++)
	{
		scanf("%d %d %d", &i, &a, &b);
		g[a][b] = 1;
	}
}


bool dfs(int p){
	for (int i = 0; i < m; i ++)
	{
		if (!visited[i] && g[p][i])
		{
			visited[i] = 1;
			int t = match[i];
			match[i] = p;
			if (-1 == t || dfs(t))
			{
				return true;
			}
			match[i] = t;
		}
	}
	return false;
}

void solve(){
	int cnt = 0, i;	
	memset(match, 0xff, sizeof(match));
	for (i = 0; i < n; i ++)
	{
		memset(visited, 0, sizeof(int) * m);
		if (dfs(i))	cnt++;
	}
	printf("%d\n", cnt);
}

int main(){
	while (EOF != scanf("%d", &n))
	{
		if (0 == n)	break;
		input();
		solve();		
	}
	return 0;
}