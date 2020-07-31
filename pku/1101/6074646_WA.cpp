//


#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)
#define Inf 0x7fffffff
#define MAXN 100000

int w, h;
int x1, y1, x2, y2;
char maze[100][100];
//int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int dist[100][100];
int dd[100][100];

int ans;
int q[MAXN][2];

bool inMaze(const int &x, const int &y){
    return 0 <= x && x <= h+1 && 0 <= y && y <= w+1;
}


void bfs(){
    int head, tail;
    memset(dist, -1, sizeof(dist));
    memset(dd, -1, sizeof(dd));
    head = tail = dist[x1][y1] = 0;

    q[tail][0] = x1;
    q[tail++][1] = y1;

    while (head < tail)
    {
        int x0 = q[head][0];
        int y0 = q[head][1];
        //printf("[%d %d]\n", x0, y0);
        head++;
        if (x0 == x2 && y0 == y2)
        {
            ans = min(dist[x0][y0], ans);
        }

        REP (i, 4)
        {
            int x = x0 + dir[i][0];
            int y = y0 + dir[i][1];

            if (!inMaze(x, y))  continue;

            if (x == x2 && y == y2 || 'X' != maze[x][y])
            {
                int tmp = dist[x0][y0];
                if (i != dd[x0][y0])    tmp++;
                if (-1 == dist[x][y])
                {
                    dd[x][y] = i;
                    dist[x][y] = tmp;
                    q[tail][0] = x;
                    q[tail++][1] = y;
                }
            }
        }
    }
}


int main(){
    int t = 1, m;
    while (EOF != scanf("%d %d\n", &w, &h))
    {
        if (0 == w && 0 == h)   break;
        memset(maze, 0, sizeof(maze));
        FOR (i, 1, h+1)
        {
            gets(maze[i]+1);
            //scanf("%*c");
        }
        //out(maze, w+2, h+2);
        printf("Board #%d:\n", t++);

        m = 0;

        while (EOF != scanf("%d %d %d %d", &y1, &x1, &y2, &x2))
        {
            //printf("[%d %d %d %d]\n", x1, y1, x2, y2);
            if (0 == x1 &&0 == y1 && 0 == x2 && 0 == y2)    break;
            ans = Inf;
            bfs();

            printf("Pair %d: ", ++m);
            if (Inf == ans)  printf("impossible.\n");
            else printf("%d segments.\n", ans);
        }
        printf("\n");
    }
    return 0;
}
