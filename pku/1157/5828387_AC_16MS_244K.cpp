#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)


#define MAXN 110

int f[MAXN][MAXN], g[MAXN][MAXN];
int n, m;

int main(){
    while (EOF != scanf("%d %d", &n, &m))
    {
        REP (i, n)
        {
            REP (j, m)
            {
                scanf("%d", &g[i][j]);
                f[i][j] = 0;
            }
        }
        REP (j, m)
        {
            f[0][j] = g[0][j];
            //if (j)  f[0][j] = max(f[0][j-1], f[0][j]);
        }
        FOR (i, 1, n)
        {
            FOR (j, i, m)
            {
                FORD (k, j-1, i-1)
                {
                    f[i][j] = max(f[i][j], f[i-1][k] + g[i][j]);
                }
            }
        }
        //out(f, n, m);
        int ans = 0;

        FOR (i, n-1, m)
        {
            if (ans < f[n-1][i])    ans = f[n-1][i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
