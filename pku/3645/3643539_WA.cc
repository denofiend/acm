// 3645(pku)

#include <iostream>
#include <ctype.h>
#define MAXN 10000
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }


char str[MAXN];

int main(){
    double p, e1, e2;
    while (gets(str))
    {
        if (isdigit(str[0]))
        {
            sscanf(str, "%lf", &p);
            printf("%.2lf\n", p);
        }
        else if ('(' == str[0] && ')' == str[1])
        {
            break;
        }
        else
        {
            sscanf(str, "(%lf %lf %lf)", &p, &e1, &e2);
            printf("%.2lf\n", p * (e1 + e2) + p * (e1 - e2));
        }
    }
    return 0;
}
