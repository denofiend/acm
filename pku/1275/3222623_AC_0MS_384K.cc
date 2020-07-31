// 1275(pku)
// DenoFiend
// 查分约束系统

#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i <= n; i ++)   cout << x[i] << ' '; cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i <= n; i ++ )  out(x[i], m);   cout << endl;   }

//
int g[30][30], r[30], t[30], visited[30][30], dist[30];

int n;
void input(){
    int i, rpos;
    memset(r, 0, sizeof(r));
    memset(t, 0, sizeof(t));
    memset(g, 0, sizeof(g));
    memset(visited, 0, sizeof(visited));
    for (i = 1; i <= 24; i ++)  scanf("%d", &r[i]);
    memset(t, 0, sizeof(t));
    scanf("%d", &n);
    for (i = 0; i < n; i ++)
    {
        scanf("%d", &rpos);
        t[rpos + 1] ++;
    }
}
// 建图
void init(){
    int i;
    for (i = 1; i <= 8; i ++)
    {
        g[i - 1][i] = 0;
        visited[i - 1][i] = 1;
        g[i][i - 1] = -t[i];
        visited[i][i - 1] = 1;
        visited[i + 16][i] = 1;
    }
    for (; i <= 24; i ++)
    {
        g[i - 1][i] = 0;
        visited[i - 1][i] = 1;
        g[i][i - 1] = -t[i];
        visited[i][i - 1] = 1;

        g[i - 8][i] = r[i];
        visited[i - 8][i] = 1;
    }
    for (i = 1; i <= 24; i ++)
    {
        g[0][i] = 0;
        visited[0][i] = 1;
    }
    visited[0][24] = 1;
}
// bellmanFord()判断是否是正权值回路
bool bellmanFord(int sum){
    int i, j, k;
    for (i = 1; i <= 8; i ++)
        g[i + 16][i] = r[i] - sum;
    g[0][24] = sum;
    memset(dist, 0, sizeof(dist));
    bool flag;
    for (k = 0; k <= 25; k ++)
    {
        if (25 == k)   return false;
        flag = false;
        for (i = 0; i < 25; i ++)
            for (j = 0; j < 25; j ++)
                if (visited[i][j])
                {
                    if (dist[i] + g[i][j] > dist[j])
                    {
                        dist[j] = dist[i] + g[i][j];
                        flag = true;
                    }
                }
        if (!flag)  break;
    }
    return true;
}
void solve(){
    if (!bellmanFord(n)) printf("No Solution\n");
    else
    {
        // 二分枚举 s[24]
        // 如果S24＝x的时候存在可行解，那么S24＝x＋1的时候也存在可行解；
        // 且如果S24＝x时不存在可行解，那么S24＝x－1时也不存在可行解
        // 利用二分查找
        int left = 0, right = n, mid;
        while (left != right)
        {
            mid = (left + right) / 2;
            if (bellmanFord(mid))   right = mid;
            else    left = mid + 1;
        }
        printf("%d\n", left);
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        init();
        solve();
    }
    return 0;
}
