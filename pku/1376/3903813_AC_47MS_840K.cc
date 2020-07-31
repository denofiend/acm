//

#include <iostream>
#define MAXN 20000
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;}
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);  cout << endl;}


int dist[MAXN][5];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;
int g[64][64];
int queue[MAXN], oriQ[MAXN];
int start, end, orition;
char ori[10];

void input(){
    int i, j;
    memset(g, 0, sizeof(g));
    for (j = 0; j <= m + 1; j ++)   g[0][j] = 1;
    for (i = 1; i <= n; i ++)
    {
        g[i][0] = 1;
        for (j = 1; j <= m; j ++)
        {
            scanf("%d", &g[i][j]);
            //g[i][j + 1] = g[i + 1][j] = g[i + 1][j + 1] = 1;
        }
        g[i][m + 1] = 1;
    }
    for (j = 0; j <= m + 1; j ++) g[n + 1][j] = 1;
    //out(g, n + 2, m + 2);
    int x, y;
    scanf("%d %d", &x, &y);
    start = x * m + y;

    scanf("%d %d", &x, &y);
    end = x * m + y;
    scanf("%s", ori);

    memset(dist, 0xff, sizeof(dist));
    // east, south, weast, north
    //
    if ('e' == ori[0]) orition = 0;
    else if ('s' == ori[0]) orition = 1;
    else if ('w' == ori[0]) orition = 2;
    else if ('n' == ori[0]) orition = 3;
}


void bfs(){
    int i, head, tail;
    head = tail = 0;
    queue[tail] = start;
    oriQ[tail++] = orition;
    dist[start][orition] = 0;

    while (head < tail)
    {
        int tmp = queue[head], newPos, oriTmp, x, y, newO;
        oriTmp = oriQ[head++];
        //printf("{%d %d %d}\n", tmp / m, tmp % m, oriTmp);
        if (tmp == end)
        {
            printf("%d\n", dist[tmp][oriTmp]);
            return;
        }
        int tx = tmp / m, ty = tmp % m;
        //printf("[%d %d]\n", tx, ty);

        newO = (oriTmp + 1) % 4;

        if (-1 == dist[tmp][newO])
        {
            oriQ[tail] = newO;
            queue[tail++] = tmp;
            dist[tmp][newO] = dist[tmp][oriTmp] + 1;
        }

        newO = (oriTmp + 3) % 4;
        if (-1 == dist[tmp][newO])
        {
            oriQ[tail] = newO;
            queue[tail++] = tmp;
            dist[tmp][newO] = dist[tmp][oriTmp] + 1;
        }

        for (i = 1; i <= 3; i ++)
        {
            x = tx + dir[oriTmp][0] * i;
            y = ty + dir[oriTmp][1] * i;
            if (0 == x || n == x || 0 == y || m == y) break;
            if (1 == g[x][y] || 1 == g[x][y + 1] || 1 == g[x + 1][y] || 1 == g[x + 1][y + 1])   break;
            //printf("[%d %d]\n", x, y);
            newPos = x * m + y;

            if (-1 == dist[newPos][oriTmp])
            {
                //printf("<%d %d>\n", x, y);
                dist[newPos][oriTmp] = dist[tmp][oriTmp] + 1;
                oriQ[tail] = oriTmp;
                queue[tail++] = newPos;
            }
        }
    }
    printf("-1\n");
}

int main(){
    while (EOF != scanf("%d %d", &n, &m))
    {
        if (0 == n && 0 == m)   break;
        input();
        bfs();
    }
    return 0;
}
