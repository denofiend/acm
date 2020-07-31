// 1274(pku)
//

#include <string.h>
#include <stdio.h>
#define MAXN 210

int g[MAXN][MAXN];

int visited[MAXN], rmatchl[MAXN];
int n, m;

void input(){
    int i, j;
    int to;
    memset(g, 0, sizeof(g));

    for (i = 1; i <= n; i ++)
    {
        scanf("%d", &j);
        while (j --)
        {
            scanf("%d", &to);
            g[i][to] = 1;
        }
    }
}

int dfs(int p){
    int t;
    for (int i = 1; i <= m; i ++)
    {
        if (!visited[i] && g[p][i])
        {
            visited[i] = 1;

            t = rmatchl[i];
            rmatchl[i] = p;
            if (-1 == t || dfs(t))
                return 1;
            rmatchl[i] = t;
        }
    }
    return 0;
}
void solve(){
    memset(rmatchl, 0xff, sizeof(rmatchl));

    int i, cnt = 0;
    for (i = 1; i <= n; i ++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
        {
            cnt ++;
        }
    }
    printf("%d\n", cnt);
}
int main(){
    while (2 == scanf("%d%d", &n, &m))
    {
        input();
        solve();
    }
    return 0;
}
