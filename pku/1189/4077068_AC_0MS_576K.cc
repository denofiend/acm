//

#define OUT(x) (cout << #x << " = " << x << endl)
#include <iostream>
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

int n, m, a[100][100];
long long p[100][100][2];

inline long long gcd(long long a, long long b){
    if (0 == b) return a;
    else return gcd(b, a % b);
}

// return c/d += a/b
inline void add(long long a, long long b, long long &c, long long &d){
    long long t1, t2, t3, t4;
    t1 = gcd(b, d);
    t2 = b / t1 * d;
    t3 = d / t1 * a;
    t4 = b / t1 * c;

    c = t3 + t4;
    d = t2;
    t1 = gcd(c, d);
    c /= t1;
    d /= t1;
}

int main () {
    int i, j;
    char s[100];
    while (EOF != scanf("%d%d", &n, &m))
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++)
            {
                scanf("%s", s);
                if ('*' == s[0])    a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        memset(p, 0, sizeof(p));

        for (i = 1; i <= n + 1; i++)
            for (j = 1; j <= i; j++)
            {
                p[i][j][0] = 0;
                p[i][j][1] = 1;
            }

        p[1][1][0] = p[1][1][1] = 1;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++)
            {
                if (1 == a[i][j])
                {
                    add(p[i][j][0], 2 * p[i][j][1], p[i+1][j][0], p[i+1][j][1]);
                    add(p[i][j][0], 2 * p[i][j][1], p[i+1][j+1][0], p[i+1][j+1][1]);
                }
                else
                {
                    add(p[i][j][0], p[i][j][1], p[i+2][j+1][0], p[i+2][j+1][1]);
                }
            }
        }
        printf("%I64d/%I64d\n", p[n+1][m+1][0], p[n+1][m+1][1]);
    }
    return 0;
}
