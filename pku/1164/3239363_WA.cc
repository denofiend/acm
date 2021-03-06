// 1164(pku)
// DenoFiend

#include <iostream>
#define MAXN 100
using namespace std;


int n, m, sum[MAXN][MAXN];
int visited[MAXN][MAXN];

int dir[9][2] = { {0, 0}, {0, -1}, {-1, 0}, {0, 0}, {0, 1}, {0, 0}, {0, 0}, {0, 0}, {1, 0} };

// hash to position of the dir array
char map[16][5] = { "", "1", "2", "12", "4", "14", "24", "124", "8", "18", "28", "128", "48", "", "248", "1248" };

// dfs找连通的屋子
int dfs(int p, int q){
    visited[p][q] = 1;
    //if (15 == sum[p][q])    return 1;
    int mapid = 15 - sum[p][q];
    int len = strlen(map[mapid]);

    int area = 1;
    for (int i = 0; i < len; i ++)
    {
        int x = p + dir[map[mapid][i] - '0'][0];
        int y = q + dir[map[mapid][i] - '0'][1];
        if (!visited[x][y])
            area += dfs(x, y);
    }
    return area;
}

int main(){
    scanf("%d %d", &n, &m);
    int i, j;
    for (i = 1; i <= n; i ++)
        for (j = 1; j <= m; j ++)
            scanf("%d", &sum[i][j]);
    memset(visited, 0, sizeof(visited));
    int num = 0, max = 0;
    for (i = 1; i <= n; i ++)
    {
        for (j = 1; j <= m; j ++)
            if (!visited[i][j])
            {
                int area = dfs(i, j);
                num++;
                if (max < area) max = area;
            }
    }
    printf("%d\n%d\n", num, max);
    return 0;
}
