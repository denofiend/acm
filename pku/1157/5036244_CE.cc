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
    int i, j, k;
    while (2 == scanf("%d %d", &F, &V))
    {
        for (i = 1; i <= F; i ++)
        {
            for (j = 1; j <= V; j ++)
            {
                scanf("%d", &val[i][j]);
            }
        }

//        for (i = 1; i <= V; i ++)   f[i][i] = f[i - 1][i - 1] + val[i][i];
//        //out(f, V + 1, F + 1);
//        for (i = 1; i <= V; i ++)
//        {
//            for (j = 1; j < i; j ++)
//            {
//                f[i][j] = max(f[i - 1][j - 1] + val[j][i], f[i - 1][j]);
//            }
//        }


        for (j = 1; j <= V; ++j)    f[1][j] = val[j];
        for (i = 2; i <= F; ++i)
        {
            for (j = i; j <= V; ++j)
            {
                f[i][j] = 0;
                for (k = i; k < j; ++k)
                {
                    f[i][j] = max(f[i][j], f[i-1][k]+val[i][j]);
                }
            }
        }
        int ans = 0;
        for (i = F; i <= V; ++i)
            if (ans < f[F][i])  ans = f[F][i]);

        //out(f, V + 1, F + 1);
        printf("%d\n", f[V][F]);
    }
    return 0;
}
