//

#include <iostream>
#define MAXN 15000
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;}
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);  cout << endl;}


int dist[MAXN][4];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;
int g[55][55];
int queue[MAXN], oriQ[MAXN];
int start, end, orition;
char ori[10];

void input(){
    int i, j, flag;
    memset(g, 0, sizeof(g));
    for (i = 0; i < n; i ++)
        for (j = 0; j < m; j ++)
        {
            scanf("%d", &flag);
            if (1 == flag)
            {
                g[i][j] = g[i][j + 1] = g[i + 1][j] = g[i + 1][j + 1] = 1;
            }
        }
    //out(g, n, m);
    int x, y;
    scanf("%d %d", &x, &y);
    start = x * n + y;

    scanf("%d %d", &x, &y);
    end = x * n + y;
    scanf("%s", ori);

    memset(dist, 0xff, sizeof(dist));
    // east, south, weast, north
    //
    if ('e' == ori[0]) orition = 0;
    else if ('s' == ori[0]) orition = 1;
    else if ('w' == ori[0]) orition = 2;
    else orition = 3;
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
        //printf("{%d %d %d}\n", tmp / n, tmp % n, oriTmp);
        if (tmp == end)
        {
            printf("%d\n", dist[tmp][oriTmp]);
            return;
        }
        int tx = tmp / n, ty = tmp % n;
        //printf("[%d %d]\n", tx, ty);

        newO = (oriTmp + 1) % 4;
        if (-1 == dist[tmp][newO] || dist[tmp][oriTmp] + 1 < dist[tmp][newO])
        {
            oriQ[tail] = newO;
            queue[tail++] = tmp;
            dist[tmp][newO] = dist[tmp][oriTmp] + 1;
        }

        newO = (oriTmp + 3) % 4;
        if (-1 == dist[tmp][newO] || dist[tmp][oriTmp] + 1 < dist[tmp][newO])
        {
            oriQ[tail] = newO;
            queue[tail++] = tmp;
            dist[tmp][newO] = dist[tmp][oriTmp] + 1;
        }

        for (i = 1; i <= 3; i ++)
        {
            x = tx + dir[oriTmp][0] * i;
            y = ty + dir[oriTmp][1] * i;
            if (!(0 <= x && x < n && 0 <= y && y < m)) continue;
            if (1 == g[x][y])   break;
            //printf("[%d %d]\n", x, y);
            newPos = x * n + y;

            if (-1 == dist[newPos][oriTmp] || dist[tmp][oriTmp] + 1 < dist[newPos][oriTmp])
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
