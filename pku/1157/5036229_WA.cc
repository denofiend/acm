// 1157(pku)


#include <iostream>
#define INF -200
#define MAXN 110
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }


int main(){
    int F, V;
    int val[MAXN][MAXN], f[MAXN][MAXN];
    int i, j;
    while (2 == scanf("%d %d", &F, &V))
    {
        for (i = 1; i <= F; i ++)
        {
            for (j = 1; j <= V; j ++)
            {
                scanf("%d", &val[i][j]);
            }
        }

        for (i = 1; i <= V; i ++)   f[i][i] = f[i - 1][i - 1] + val[i][i];
        //out(f, V + 1, F + 1);
        for (i = 1; i <= V; i ++)
        {
            for (j = 1; j <= i; j ++)
            {
                f[i][j] = max(f[i - 1][j - 1] + val[j][i], f[i - 1][j]);
            }
        }
        //out(f, V + 1, F + 1);
        printf("%d\n", f[V][F]);
    }
    return 0;
}
