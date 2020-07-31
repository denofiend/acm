//
// 建图: 重-->轻
// 拓扑排序: 如度为零时，优先选择标号大者
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

const int N = 201;

// 图的邻接表
struct Adj{
    int id, ls[N];
    Adj(){ id = 0; }
}adj[N];

int in[N]; // 入度
int res[N]; // 存储结果
bool TopoOrder(int n); // 拓扑排序

int main(void){
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
    {
        memset(adj, 0, sizeof(adj));
        memset(in, 0, sizeof(in));
        int i, n, m;
        scanf("%d%d", &n, &m);
        for (i = 0; i < m; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[b].ls[ adj[b].id++ ] = a;
            ++in[a];
        }
        //out(in, n + 1);
        if (0 == TopoOrder(n)) printf("-1\n");
        else
        {
            printf("%d", res[1]);
            for (i = 2; i <= n; ++i) printf(" %d", res[i]);
            printf("\n");
        }
    }
    return 0;
}
// 不是单纯的拓扑排序:尽可能使小标号标注weight更小的球
bool TopoOrder(int n){
    priority_queue<int> Q;
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        if (0 == in[i]) Q.push(i);
    }
    for (i = n; i >= 1; --i)
    {
        if (Q.empty()) return 0;
        else
        {
            int u = Q.top();
            Q.pop();
            res[u] = i; //
            for (j = 0; j < adj[u].id; ++j)
            {
                --in[ adj[u].ls[j] ];
                if (0 == in[ adj[u].ls[j] ]) Q.push(adj[u].ls[j]);
            }
        }
    }
    return 1;

}
