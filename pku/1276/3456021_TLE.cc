// 背包

#include <iostream>
#define MAXN 1001
#define MAXX 100001
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n ; i++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out(x[i], m);   cout << endl;   }

int nk[MAXN], dk[MAXN];
int cash, n;

int f[2][MAXX];

void input(){
    scanf("%d", &n);
    memset(nk, 0, sizeof(int) * n);
    memset(dk, 0, sizeof(int) * n);

    for (int i = 1; i <= n; i ++)
    {
        scanf("%d%d", &nk[i], &dk[i]);
    }
    //out(nk, n + 1);
    //out(dk, n + 1);
}

void solve(){
    memset(f, 0, sizeof(f));
    int i, j, k;
    int pre = 0, curr = 1;
    for (i = 1; i <= n; i ++)
    {
        for (k = 0; k < nk[i]; k ++)
        {
            for (j = dk[i]; j <= cash; j++)
            {
                if (f - dk[i] < 0)
                {
                    f[curr][j] = f[pre][j];
                    continue;
                }
                if (f[pre][j] > f[pre][j - dk[i]] + dk[i])
                {
                    f[curr][j] = f[pre][j];
                }
                else
                {
                    f[curr][j] = f[pre][j - dk[i]] + dk[i];
                }
            }
            pre = curr;
            curr = (curr + 1) % 2;
        }
    }
    //out(f, 2, cash + 1);
    printf("%d\n", f[1][cash]);
}

int main(){
    while (EOF != scanf("%d", &cash))
    {
        input();
        solve();
    }
    return 0;
}
