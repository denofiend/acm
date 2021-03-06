// 3645(pku)

#include <iostream>
#include <ctype.h>
#define MAXN 10000
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }


char str[MAXN];

double solve(char *s){
    //printf("%s\n", s);
    double p;
    if (isdigit(s[0]))
    {
        sscanf(s, "%lf", &p);
        return p;
    }
    else if ('(' == s[0])
    {
        sscanf(s, "(%lf", &p);

        for (; ' ' != *s && ')' != *s; s++);

        //puts(s);
        s ++;
        double x = solve(s);

        s++;
        for (s ++; ' ' != *s && ')' != *s; s++);
        double y = solve(s);

        return p * (x + y) + p * (x - y);
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
        printf("%.2lf\n", solve(str));
    }
    return 0;
}
