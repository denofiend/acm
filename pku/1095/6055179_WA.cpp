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

long long f[MAXN];
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
    /*
    REP (i, 17)
    {
        printf("[%d %I64d]\n", i, f[i]);
    }
    */
}
int left, right, tmp, mm;

void output(int n, long long nth){
    //printf("output[%d %I64d]\n", n, nth);
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
    int left = n-1, right = 0;
    long long tmp = nth;
    //OUT(tmp);
    REP (i, n)
    {
        long long mm = f[i] * f[n-1-i];
        //OUT(tmp);
        //OUT(mm);
        if (tmp > mm)   tmp -= mm;
        else
        {
            left = i;
            right = n-1-i;
            break;
        }
    }
    //printf("<%d %d>\n", left, right);
    //OUT(tmp);

    long long ri = 0, lo = 0;
    if (0 == right)
    {
        ri = 1;
        lo = tmp / f[left];
        lo = tmp - lo * f[left];
    }
    else
    {
        if (0 == left)
        {
            lo = 1;

            ri = tmp / f[right];
            ri = tmp - ri * f[right];
        }
        else
        {
            if (f[right] >= tmp)
            {
                lo = 1;
                ri = tmp;
            }
            else
            {
                lo = tmp / f[right];
                ri = tmp - lo * f[right];
                lo++;

                tmp = lo / f[left];
                lo -= tmp * f[left];

            }
        }
    }


    //printf("[%I64d %I64d]\n\n", lo, ri);
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
