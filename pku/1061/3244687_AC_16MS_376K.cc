// 1061(pku)
// 扩展欧几里德求ax + by = c

#include <iostream>
#define MOD(x, y)   ((x) % (y) + y) % (y)
using namespace std;


long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (0 == b)
    {
        x = 1; y = 0;
        return a;
    }
    else
    {
        long long tx, ty, d;
        d = ext_gcd(b, MOD(a, b), tx, ty);
        x = ty;
        y = tx - a / b * ty;
        return d;
    }
}

int main(){
    long long x, y, m, n, L;
    scanf("%I64d%I64d%I64d%I64d%I64d\n", &x, &y, &m, &n, &L);
    if (m == n) printf("Impossible\n");
    else
    {
        long long a, b, c;
        b = L;
        a = m - n;
        c = y - x;

        long long rx, ry;
        long long d = ext_gcd(a, b, rx, ry);

        if (0 != c % d)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%I64d\n", MOD(rx * c / d, b / d));
        }
    }
    return 0;
}
