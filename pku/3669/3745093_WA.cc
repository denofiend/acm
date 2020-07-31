//



#include <iostream>
#define MAXN 100000
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out(x[i], m);   cout << endl; }

int queue[MAXN];
int g[310][310], visited[310][310];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void input(){
    int n, a, b, t;
    memset(g, 0xff, sizeof(g));
    memset(visited, 0, sizeof(visited));
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d %d %d", &a, &b, &t);
        if (-1 == g[a][b] || g[a][b] > t)   g[a][b] = t;
        for (int j = 0; j < 4; j ++)
        {
            int x = a + dir[j][0];
            int y = b + dir[j][1];
            if (-1 == g[x][y] || g[x][y] > t)   g[x][y] = t;
        }
    }
    //out(g, 3, 3);
}

void bfs(){
    if (-1 == g[0][0])
    {
        printf("0\n");
        return;
    }
    int head = 0, tail = 0, taill, step = 0, i, j;
    queue[tail++] = 0;
    visited[0][0] = 1;

    while (head < tail)
    {
        taill = tail;

        for (i = head; i < tail; i ++)
        {
            int tmp = queue[i];
            int ax = tmp / 301;
            int by = tmp % 301;
            for (j = 0; j < 4; j ++)
            {
                int x = ax + dir[j][0];
                int y = by + dir[j][1];
                if (!(0 <= x && 0 <= y && !visited[x][y]))    continue;
                else if (!(0 <= x && 0 <= y))
                {
                    printf("%d\n", step);

                }
                visited[x][y] = 1;
                //printf("[%d %d]\n", x, y);
                if (-1 == g[x][y])
                {
                    printf("%d\n", step);
                    return;
                }
                if (-1 != g[x][y] && step <= g[x][y])
                {
                    int newone = x * 301 + y;
                    step = g[x][y];
                    queue[taill++] = newone;
                }
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
