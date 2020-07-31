// 1061(pku)
//

#include <iostream>
#include <cmath>
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
        d = ext_gcd(b, a % b, tx, ty);
        x = ty; y = tx - a / b * ty;
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
        if (m > n)
        {
            a = m - n;
            c = y - x;
        }
        else
        {
            a = n - m;
            c = x - y + L;
        }
        long long rx, ry;
        long long d = ext_gcd(a, b, rx, ry);
        //printf("<%I64d, %I64d, %I64d>\n", d, rx, ry);
        if (0 != c % d)     printf("Impossible\n");
        else
        {
            printf("%I64d\n", rx * c / d);
        }
    }
    return 0;
}
