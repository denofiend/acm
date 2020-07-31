//


#include <iostream>
#include <algorithm>
using namespace std;

template <class T> void out(T x, int n){ for (int i = 0; i < n; ++i) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; ++i) out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define RORD(i, a, b)   for (int i = (int)a; i >= (int)b; --i)
#define MAXN 200
#define Inf 1000000000
typedef int elem_t;

int g[MAXN][MAXN], g1[MAXN][MAXN], visited[MAXN];
int n, s, flag[MAXN], pre[MAXN];

struct Node{
    int id, dis;
};
Node mindis[MAXN];

void dijkstra(int n, elem_t mat[][MAXN], int s, Node* min, int* pre){
	int i, j, k;
	for (i = 0; i < n; i++)
		min[i].dis = Inf, visited[i] = 0, pre[i] = -1;
    min[s].dis = 0;

	for (j = 0; j < n; j++)
	{
	    k = - 1;
		for (i = 0; i < n; i++)
			if (!visited[i] && (-1 == k || min[i].dis < min[k].dis))
				k = i;
        visited[k] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i] && min[k].dis + mat[k][i] < min[i].dis && 0 <= mat[k][i])
			{
			    pre[i] = k;
				min[i].dis = min[k].dis + mat[k][i];
			}
	}
}
bool cmp(const Node &a, const Node &b){
    return a.dis < b.dis;
}

int main(){
    int t1;
    char c;

    scanf("%d", &n);
    REP (i, n)
        REP (j, n)
            scanf("%d", &g[i][j]);

    scanf("%d ", &s);
    s--;
    memset(flag, 0, sizeof(flag));
    while (EOF != scanf("%d%c", &t1, &c))
    {
        flag[t1-1] = 1;
        if ('\n' == c)  break;
    }

    REP (i, n)
    {
        mindis[i].id = i;
        REP (j, n)
        {
            if (-1 == g[i][j]) g1[j][i] = Inf;
            else g1[j][i] = g[i][j];
        }
    }

    dijkstra(n, g1, s, mindis, pre);
    sort(mindis, mindis+n, cmp);

    printf("Org\tDest\tTime\tPath\n");
    REP (i, n)
    {
        if (flag[mindis[i].id])
        {
            printf("%d\t%d\t%d", mindis[i].id+1, s+1, mindis[i].dis);
            int fa = mindis[i].id;
            while (fa != s)
            {
                printf("\t%d", fa+1);
                fa = pre[fa];
            }
            printf("\t%d\n", fa+1);
        }
    }

    return 0;
}

