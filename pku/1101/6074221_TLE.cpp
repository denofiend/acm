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

int w, h;
int x1, y1, x2, y2;
char maze[100][100];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int vis[100][100];
int ans;

bool inMaze(const int &x, const int &y){
    return 0 <= x && x <= h+1 && 0 <= y && y <= w+1;
}

void dfs(int x0, int y0, int dd, int cost){
    //printf("dfs[%d %d %d %d]\n", x0, y0, dd, cost);
    if (x0 == x2 && y0 == y2)
    {
        if (cost < ans) ans = cost;
        return;
    }

    vis[x0][y0] = 1;

    int x, y;
    REP (i, 4)
    {
        x = x0 + dir[i][0];
        y = y0 + dir[i][1];
        if (inMaze(x, y) && !vis[x][y] && (x2 == x && y2 == y || 'X' != maze[x][y]))
        {
            if (i == dd)
            {
                dfs(x, y, dd, cost);
            }
            else
            {
                dfs(x, y, i, cost+1);
            }
        }
    }
    vis[x0][y0] = 0;
}

int main(){
    int t = 1, m, x, y;
    while (EOF != scanf("%d %d\n", &w, &h))
    {
        if (0 == w && 0 == h)   break;
        memset(maze, 0, sizeof(maze));
        FOR (i, 1, h+1)
        {
            FOR (j, 1, w+1)
            {
                scanf("%c", &maze[i][j]);
            }
            scanf("%*c");
        }

        printf("Board #%d:\n", t++);

        m = 0;

        while (EOF != scanf("%d %d %d %d", &y1, &x1, &y2, &x2))
        {
            //printf("[%d %d %d %d]\n", x1, y1, x2, y2);
            if (0 == x1 &&0 == y1 && 0 == x2 && 0 == y2)    break;
            ans = Inf;
            REP (i, 4)
            {
                x = x1 + dir[i][0];
                y = y1 + dir[i][1];
                if (inMaze(x, y) && !vis[x][y] && 'X' != maze[x][y])
                {
                    memset(vis, 0, sizeof(vis));
                    dfs(x, y, i, 1);
                }
            }
            printf("Pair %d: ", ++m);
            if (Inf == ans)  printf("impossible.\n");
            else printf("%d segments.\n", ans);
        }
        printf("\n");
    }
    return 0;
}
