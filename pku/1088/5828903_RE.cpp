#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;


template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)

#define MAXN 700

int g[MAXN][MAXN];
int n, m;
int f[MAXN][MAXN];


int rec(int x, int y){
    if (-1 != f[x][y])  return f[x][y];

    int tmp = 0;

    if (1 <= x)
    {
        if (g[x][y] >= g[x-1][y])   tmp = max(tmp, rec(x-1, y) + 1);
    }

    if (x+1 < n)
    {
        if (g[x][y] >= g[x+1][y])
        {
            tmp = max(tmp, rec(x+1, y) + 1);
        }
    }

    if (1 <= y)
    {
        if (g[x][y] >= g[x][y-1])
        {
            tmp = max(tmp, rec(x, y-1) + 1);
        }
    }

    if (y+1 < m)
    {
        if (g[x][y] >= g[x][y+1])
        {
            tmp = max(tmp, rec(x, y+1) + 1);
        }
    }

    return f[x][y] = tmp;
}

int main(){
    while (EOF != scanf("%d %d\n", &n, &m))
    {
        REP (i, n)
        {
            REP (j, m)
            {
                scanf("%d", &g[i][j]);
                f[i][j] = -1;
            }
        }

        int ans = 0;
        REP (i, n)
        {
            REP (j, m)
            {
                int tmp = rec(i, j);
                if (tmp > ans)  ans = tmp;
            }
        }
        printf("%d\n", ans+1);
    }
    return 0;
}
