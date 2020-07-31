//


#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>


using namespace std;


template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){  for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)
#define Inf 0x7fffffff
#define MAXN 3010



int f[2][MAXN];
int s[2][MAXN];
int p[MAXN];
int x[MAXN];


int main(){
    int t, n, m, mm, w, lo, ri, a, b;
    while (EOF != scanf("%d %d", &n, &m))
    {
        {
            n++;
            m++;
            FOR (i, 1, n) scanf("%d", &x[i]);
            sort(x + 1, x + n);

            p[1] = x[1];
            FOR (i, 2, n)   p[i] = p[i-1] + x[i];

            FOR (j, 1, n)
            {
                mm = (j+1) / 2;
                lo = mm - 1;
                ri = j - 1 - lo;
                if (lo < 0) lo = 0;
                if (ri < 0) ri = 0;

                f[0][j] = lo * x[mm] - p[lo] + p[j] - p[mm] - ri * x[mm];
                s[0][j] = 1;
            }
            //out(f[0], n);

            s[0][n] = s[1][n] = n-1;

            FOR (i, 1, m)
            {
                 FORD (j, n-1, i)
                 {
                    f[i%2][j] = Inf;
                    a = s[(i+1)%2][j];
                    b = s[i%2][j+1] + 1;
                    FOR (k, a, b)
                    {
                        // O(1) 计算[k+1, j] 的最小值和
                        mm = (k+1+j) / 2;
                        lo = mm - k - 1;
                        ri = j - k - 1 - lo;

                        w = lo * x[mm] - p[mm-1] + p[k] + p[j] - p[mm] - ri * x[mm] + f[(i+1)%2][k];

                        if (f[i%2][j] > w)
                        {
                            f[i%2][j] = w;
                            s[i%2][j] = k;
                        }
                    }
                }
            }
            printf("%d\n", f[m%2][n-1]);
        }
    }
    return 0;
}
