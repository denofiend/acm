#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl ;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)
#define Inf 500000000
#define MAXN 200

int f[MAXN];
void init(){
    f[0] = f[1] = 1;
    FOR (i, 2, MAXN)
    {
        f[i] = 0;
        REP (j, i)
        {
            f[i] += f[j] * f[i-1-j];
        }
    }
}
int left, right, tmp, mm;

void output(int n, int nth){
    //printf("output[%d %d]\n", n, nth);

    if (0 == nth || 1 == nth)
    {
        printf("X");
        if (n > 1)
        {
            printf("(");
            output(n-1, nth);
            printf(")");
        }
        return;
    }
    int left, right;
    int tmp = nth;
    REP (i, n)
    {
        int mm = f[i] * f[n-1-i];

        if (mm < 0) break;
        if (tmp > mm)   tmp -= mm;
        else
        {
            left = i;
            right = n-1-i;
            break;
        }
    }
    //OUT(tmp);

    int ri = 0;
    if (tmp < f[right])
    {
        ri = tmp;
    }
    else if (right)
    {
        ri = tmp / f[right];
        ri *= f[right];
    }

    int lo = tmp - ri;

    //printf("<%d %d>\n", left, right);
    //printf("[%d %d]\n\n", lo, ri);
    if (left)
    {
        printf("(");
        output(left, lo);
        printf(")");
    }

    printf("X");

    if (right)
    {
        printf("(");
        output(right, ri);
        printf(")");
    }
}

int main(){
    int n, mm;
    init();
    while (EOF != scanf("%d\n", &n))
    {
        if (0 == n) break;
        FOR (i, 1, MAXN)
        {
            if (n > f[i])   n -= f[i];
            else
            {
                mm = i;
                break;
            }
        }
       // OUT(mm);
       // OUT(n);
        output(mm, n);
        printf("\n");
    }
}
