// 1275(pku)


#include <iostream>
#define MAXN 50
#define INF 0xfffff
using namespace std;


template <class T> void out(T x, int n){    for (int i = 0; i <= n; i ++)   cout << x[i] << " "; cout << endl;  }
template <class T> void out(T x, int n, int m){ for (int i = 0; i <= n; i ++)   out(x[i], m);}

int r[MAXN], t[MAXN];

int g[MAXN][MAXN];

int dist[MAXN], n, ans;
void input(){
    int i, j;
    for (i = 0; i <= 23; i ++)  scanf("%d", &r[i]), t[i] = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i ++)
    {
        scanf("%d", &j);
        t[j] ++;
    }
}
void addEdge(int sum){
    memset(g, 0xff, sizeof(g));
    for (int i = 0; i <= 23; i ++)
    {
        if (i == 0) g[i][25] = -t[i], g[25][i] = 0;
        else    g[i][i - 1] = -t[i], g[i - 1][i] = 0;
        g[25][23] = sum;
        if (i <= 7) g[i + 16][i] = r[i] - sum;
        else if (i >= 8)    g[i - 8][i] = r[i];
        g[25][i] = 0;
    }
}
void init(int sum){
    int i;
    for (i = 0; i <= 24; i ++)  dist[i] = 0;
    dist[25] = 0;
    addEdge(sum);
}
void BellmanFord(){
    ans = n + 1;
    for (int mid = n; mid; mid --)
    {
        init(mid);
        bool flag;
        for (int k = 0; k < 24; k ++)
        {
            flag = false;
            for (int i = 0; i <= 25; i ++)
                for (int j = 0; j <= 25; j ++)
                    if (dist[i] + g[i][j] > dist[j] && g[i][j] >= 0)
                    {
                        flag = true;
                        dist[j] = dist[i] + g[i][j];
                    }
            for (int i = 0; i <= 25; i ++)
                for (int j = 0; j <= 25; j ++)
                    if (dist[i] + g[i][j] > dist[j] && g[i][j] >= 0)
                        break;
            if (!flag)  break;
        }
        if (dist[23] == mid && ans > mid)
            ans  = mid;
    }
}
int main(){
    int testcase;
    scanf("%d", &testcase);
    while (testcase --)
    {
        input();
        BellmanFord();
        if (n + 1 == ans) printf("No Solution\n");
        else printf("%d\n", ans);
    }
    return 0;
}
