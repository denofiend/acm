//


#define MAXN 500
#include <iostream>
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i++) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out(x[i], m);   cout << endl;   }

long long f[MAXN][MAXN];

void init(){
    long long i, j, k, sum;
    for (i = 0; i < MAXN; i++)  f[i][0] = 1;

    f[1][1] = 1;
    for (i = 2; i < MAXN; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (i < j * 2)  f[i][j] = 0;
            else if (i == 2 * j)    f[i][j] = 1;
            else
            {
                sum = i - 2 * j;
                f[i][j] = 0;
                for (k = j; k <= sum; k++)
                {
                    f[i][j] += f[sum][k];
                }
            }
            f[i][0] += f[i][j];
        }
        f[i][i] = 1;
    }
   // out(f, 6, 6);
}

int main(){
    int n;
    init();
    while (EOF != scanf("%d", &n) && n)
    {
        printf("%d %I64d\n", n, f[n][0]);
    }
    return 0;
}

