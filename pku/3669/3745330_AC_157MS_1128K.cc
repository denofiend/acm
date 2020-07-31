//

#include <iostream>
#define MAXX 310
#define MAXN 100000
#define Inf 0xffffff
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out(x[i], m);   cout << endl; }

int queue[MAXN][2];
int g[MAXX][MAXX];
int mincost[MAXX][MAXX];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


void input(){
    int n, a, b, t, i, j;
    //memset(g, 0xff, sizeof(g));
    for (i = 0; i < MAXX; i++)
        for (j = 0; j < MAXX; j++)
            g[i][j] = mincost[i][j] = Inf;
    scanf("%d", &n);
    for (i = 0; i < n; i ++)
    {
        scanf("%d %d %d", &a, &b, &t);
        if (g[a][b] > t)   g[a][b] = t;
        for (j = 0; j < 4; j ++)
        {
            int x = a + dir[j][0];
            int y = b + dir[j][1];
            if (g[x][y] > t)   g[x][y] = t;
        }
    }
    //out(g, 3, 3);
}

void bfs(){
    int head = 0, tail = 0, taill, step, i, j, x, y;
    queue[tail][0] = 0;
    queue[tail++][1] = 0;
    mincost[0][0] = 0;

    while (head < tail)
    {
        taill = tail;

        for (i = head; i < tail; i ++)
        {
            step = mincost[ queue[i][0] ][ queue[i][1] ] + 1;
            for (j = 0; j < 4; j ++)
            {
                x = queue[i][0] + dir[j][0];
                y = queue[i][1] + dir[j][1];



                if (!(0 <= x && 0 <= y && step < g[x][y] && step < mincost[x][y]))    continue;

                if (Inf == g[x][y])
                {
                    printf("%d\n", step);
                    return;
                }
                //printf("[%d %d]\n", x, y);

                mincost[x][y] = step;
                queue[taill][0] = x;
                queue[taill++][1] = y;
            }
        }
        head = tail;
        tail = taill;
    }
    printf("-1\n");
}

int main(){
    input();
    bfs();
    return 0;
}
