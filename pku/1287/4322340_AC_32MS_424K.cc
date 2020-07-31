
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; ++i) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; ++i) out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for (int i = (int)a; i >= (int)b; --i)
#define MAXN 20000
#define MAXV 1100

struct Edge{
    int u, v, val;
};

Edge edge[MAXN];
int n, m;
int father[MAXN], rank[MAXN];

void link(int x, int y){
    if (rank[x] > rank[y])
    {
        father[y] = x;
    }
    else
    {
        father[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }
}

int findset(int x){
    if (x != father[x])
    {
        father[x] = findset(father[x]);
    }
    return father[x];
}

bool cmp(const Edge &a, const Edge &b){
    return a.val < b.val;
}

int kruskal(){
    FOR (i, 1, n+1) father[i] = i, rank[i] = 0;
    sort(edge, edge+m, cmp);

    int cnt = 0, nn = m, mst = 0;
    REP (i, m)
    {
        int u = findset(edge[i].u);
        int v = findset(edge[i].v);

        if (u != v)
        {
            link(u, v);
            mst += edge[i].val;
            cnt++;
        }
        if (cnt == n-1)
        {
            nn = i+1;
            break;
        }
    }
    return mst;
}

int main(){
    while (EOF != scanf("%d", &n))
    {
        if (0 == n) break;
        scanf("%d", &m);
        REP (i, m)  scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].val);
        printf("%d\n", kruskal());
    }
    return 0;
}
