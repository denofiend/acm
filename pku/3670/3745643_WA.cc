// 3670(pku)
// DP

#include <iostream>
#define MAXN 1000000


using namespace std;


template <class T> void out(T x, int n){    for (int i = 0; i < n; i++) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;    }

int a[MAXN], n, f[MAXN][3];


int dp(){
    f[0][0] = f[0][1] = f[0][2] = 1;
    f[0][ a[0] - 1 ] = 0;

    for (int i = 1; i < n; i ++)
    {
        f[i][0] = f[i - 1][0] + 1 - (1 == a[i]);
        f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1 - (2 == a[i]);
        f[i][2] = min(min(f[i - 1][0], f[i - 1][1]), f[i - 1][2]) + 1 - (3 == a[i]);

    }
    return min(min(f[n - 1][0], f[n - 1][1]), f[n - 1][2]);
}

int main() {
    int i, ans, ans1;
    scanf("%d", &n);
    for (i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    ans = dp();
    out(f, n, 3);
    for (i = 0; i < n; i ++)    a[i] = 4 - a[i];

    ans1 = dp();
    out(f, n, 3);
    printf("%d\n", min(ans, ans1));
    return 0;
}
