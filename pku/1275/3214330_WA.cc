// 1275(pku)


#include <iostream>
#define MAXN 550
#define INF 0xfffff
using namespace std;


template <class T> void out(T x, int n){    for (int i = 0; i <= n; i ++)   cout << x[i] << " "; cout << endl;  }
template <class T> void out(T x, int n, int m){ for (int i = 0; i <= n; i ++)   out(x[i], m);}
int r[25], t[25];

int g[MAXN][MAXN];

int dist[MAXN], n, ans;
void input(){
    int i, j;
    for (i = 0; i <= 23; i ++)  scanf("%d", &r[i]), t[i] = 0;
    //out(r, 24);
    scanf("%d", &n);
    for (i = 0; i < n; i ++)
    {
        scanf("%d", &j);
        t[j] ++;
    }
    //out(t, 24);
}
void addEdge(int sum){
    memset(g, 0xff, sizeof(g));
    //out(g, 24, 24);
    //cout << "-----------------------------" << endl;
    for (int i = 0; i <= 23; i ++)
    {
       // g[i + 1][i] = 0;
        g[i][i + 1] = 0;
        g[i][i - 1] = -t[i];
       // g[i - 1][i] = - t[i];
        //g[23][24] = sum;
        g[24][23] = sum;
        if (i <= 7) g[i + 16][i] = r[i] - sum;
        else if (i >= 8)    g[i - 8][i] = r[i];
    }
   // out(g, 24, 24);
}
void init(int sum){
    int i;
    for (i = 0; i <= 24; i ++)  dist[i] = INF;
    dist[24] = 0;
    addEdge(sum);
}
int BellmanFord(){
    //int left = 1; int right = n, mid;
    ans = n + 1;
    for (int mid = n; mid; mid --)
    {
        //mid = (left + right) / 2;
        init(mid);
        bool flag;
        for (int k = 0; k < 24; k ++)
        {
            flag = false;
            for (int i = 0; i <= 24; i ++)
                for (int j = 0; j <= 24; j ++)
                    if (dist[i] + g[i][j] < dist[j] && g[i][j] >= 0)
                    {
                        flag = true;
                        dist[j] = dist[i] + g[i][j];
                    }
            for (int i = 0; i <= 24; i ++)
                for (int j = 0; j <= 24; j ++)
                    if (dist[i] + g[i][j] < dist[j] && g[i][j] >= 0)
                        break;
            if (!flag)  break;
        }
        //printf("dist[23] = %d, mid = %d\n", dist[23], mid);
        if (dist[23] == mid && ans > mid)
                ans  = mid;
    }
    return ans;
}
int main(){
    int testcase;
    scanf("%d", &testcase);
    while (testcase --)
    {
        input();
        int ans2 = BellmanFord();
        if (n + 1 == ans2) printf("No Solution\n");
        else printf("%d\n", ans2);
    }
    return 0;
}
