//
//
//

#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; ++i) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; ++i) out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for (int i = (int)a; i >= (int)b; --i)
#define MAXN 1200

int g[MAXN][MAXN], key[MAXN];
int dfn[MAXN], low[MAXN], bb[MAXN];
int n;
void search(int n, int mat[][MAXN], int *dfn, int *low, int now, int &ret, int *key, int &cnt, int root, int &rd, int *bb){
    int i;
    dfn[now] = low[now] = ++cnt;
    for (i = 0; i < n; ++i)
    {
        if (mat[now][i])
        {
            if (!dfn[i])
            {
                search(n, mat, dfn, low, i, ret, key, cnt, root, rd, bb);
                if (low[i] < low[now])
                {
                    low[now] = low[i];
                }
                if (low[i] >= dfn[now])
                {
                    if (now != root && !bb[now])
                    {
                        key[ret++] = now, bb[now] = 1;
                    }
                    else if (now == root) rd++;
                }
            }
            else if (dfn[i] < low[now])
            {
                low[now] = dfn[i];
            }
        }
    }
}

int key_vertex(int n, int mat[][MAXN], int *key){
    int ret = 0, i, cnt, rd;
    for (i = 0; i < n; ++i) dfn[i] = bb[i] = 0;
    for (cnt = i = 0; i < n; ++i)
    {
        if (!dfn[i])
        {
            rd = 0;
            search(n, mat, dfn, low, i, ret, key, cnt ,i, rd, bb);
            if (rd > 1 && !bb[i])   key[ret++] = i, bb[i] = 1;
        }
    }
    return ret;
}

int main(){
    while (EOF != scanf("%d\n", &n))
    {
        if (0 == n) break;
        memset(g, 0, sizeof(g));
        char c;
        int u, v;
        while (1)
        {
            scanf("%d%c", &u, &c);
            if (0 == u) break;
            while (EOF != scanf("%d%c", &v, &c))
            {
                g[u-1][v-1] = g[v-1][u-1] = 1;
                if ('\n' == c)  break;
            }

        }
        printf("%d\n", key_vertex(n, g, key));
    }
    return 0;
}
