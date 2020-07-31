// 3645(pku)

#include <iostream>
#include <ctype.h>
#define MAXN 10000
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

char str[MAXN];
char *s;

double solve(){
    double p;
    int pp;
    if (isdigit(s[0]) || '-' == s[0])
    {
        sscanf(s, "%d", &pp);
        return (double)pp;
    }
    else if ('(' == s[0])
    {
        sscanf(s, "(%lf", &p);

        for (; ' ' != *s && '\0' != *s; s++);
        if ('\0' == *s) return 0.0;
        s ++;
        double x = solve();

        for (s ++; ' ' != *s && '\0' != *s; s++);
        if ('\0' == *s) return 0.0;
        s++;
        double y = solve();
        // p * (x + y) + (1 - p) * (x + y)
        // x + (p + p - 1) * y
        return x + (p + p - 1) * y;
    }
    else
    {
        return 0.0;
    }

}

int main(){
    while (gets(str))
    {
        if ('(' == str[0] && ')' == str[1])
            break;
        s = str;
        printf("%.2lf\n", solve());
    }
    return 0;
}
