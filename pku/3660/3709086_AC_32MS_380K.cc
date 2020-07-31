//

#include <iostream>
#define MAXN 110
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

bool connect[MAXN][MAXN];

int main(){
    int n, m;
    while (EOF != scanf("%d %d", &n, &m))
    {
        //memset(connect, false, sizeof(connect));
        int i, j, k, sta, end;

        for (i = 0; i < n; i ++)
            for (i = 0; i < n; i++)
                connect[i][i] = true;
        for (i = 0; i < m; i ++)
        {
            scanf("%d %d\n", &sta, &end);
            sta --, end --;
            connect[sta][end] = true;
        }

        for (k = 0; k < n; k ++)
            for (i = 0; i < n; i ++)
                if (connect[i][k])
                {
                    for (j = 0; j < n; j ++)
                        if (connect[k][j])
                        {
                            connect[i][j] = true;
                        }
                }

        //out(connect, n, n);
        int cnt = 0;
        for (i = 0; i < n; i ++)
        {
            bool ok = true;
            for (j = 0; j < n; j ++)
            {
                if (!connect[i][j] && !connect[j][i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
