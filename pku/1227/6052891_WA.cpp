//


#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl ;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)
#define MAXN 110

vector<int> g[MAXN];
map<int, int> idd;

int n, k, t;
int robot[MAXN];
int visb[MAXN];
int visa[MAXN];
int cnta[MAXN];
int cntb[MAXN];


void dfs(int u, int f){
    REP (i, g[u].size())
    {
        int v = g[u][i];

        if (1 == f && !visb[v])
        {
            visb[v] = 1;
            cntb[v]++;
            dfs(v, 0);
        }
        else if (0 == f && !visa[v])
        {
            visa[v] = 1;
            cnta[v]++;
            dfs(v, 1);
        }
    }
}
int main(){
    int u, v, m, n0;
    scanf("%d\n", &t);
    while (t--)
    {
        scanf("%d %d\n", &n, &k);
        REP (i, n)  g[i].clear();
        idd.clear();
        n0 = 0;
        REP (i, n)
        {
            scanf("%d %d", &u, &m);
            if (idd.end() == idd.find(u))
            {
                idd[u] = n0++;
            }
            u = idd[u];
            while (m--)
            {
                scanf("%d", &v);
                if (idd.end() == idd.find(v))
                {
                    idd[v] = n0++;
                }
                v = idd[v];
                g[u].push_back(v);
            }
        }

        REP (i, k)  scanf("%d", &robot[i]);

        REP (i, n)  visa[i] = visb[i] = cnta[i] = cntb[i] = 0;

        REP (i, k)
        {
            REP (j, n)  visa[j] = visb[j] = 0;
            if (!visa[robot[i]-1])
            {
                cnta[robot[i]-1]++;
                visa[robot[i]-1] = 1;
                dfs(robot[i]-1, 1);
            }
        }

        //out(cnta, n);
        //out(cntb, n);
        int ok = 0;
        REP (i, n)
        {
            if (k == cnta[i] || k == cntb[i])
            {
                ok = 1;
                break;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
