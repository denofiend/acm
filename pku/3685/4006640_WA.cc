//

#include <iostream>
#define MAXN 50010
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

long long a0[MAXN];
long long d[MAXN];


long long cal(long long i0, long long j0){
    return i0 * i0 + j0 * j0 + 100000 * (i0 - j0) + i0 * j0;
}

int main(){
    long long j, i0, j0, n0, n1, i1, j1;
    int n, m, t;
    for (j = 1; j < MAXN; j ++) a0[j] = 100001 + j * j - 100000 * j + j, d[j] = 100003 + j;
    //out(a0, 10);
    //out(d, 10);

    scanf("%d", &t);
    while (t --)
    {
        scanf("%d %d", &n, &m);
        //printf("[%d %d]\n", n, m);
        long long left = a0[n], right = INT_MAX, mid;
        i1 = 1, j1 = n;
        //printf("{%I64d %I64d}\n", left , right);
         while (left < right)
        {
            i0 = 1, j0 = n;

            mid = (left + right) >> 1;
            //printf("mid = %I64d\n", mid);
            n0 = 0;
            //printf("<%I64d %I64d %I64d>\n", left, mid, right);
            for (j = n; j >= 1; j --)
            {
                if (mid < a0[j])    continue;

                n1 = (mid - a0[j] + 2) / (2 + d[j]) + 1;
                if (n1 > n) n1 = n;
                if (cal(i0, j0) < cal(n1, j))
                {
                    i0 = n1;
                    j0 = j;
                }
                n0 += n1;
            }
            if (n0 == m)
            {
                if (cal(i1, j1) < cal(i0, j0))
                {
                    i1 = i0;
                    j1 = j0;
                }
            }
            //printf("n0 = %I64d\n", n0);
            if (n0 >= m) right = mid;
            else left = mid + 1;
        }
        printf("%I64d\n", cal(i1, j1));
    }
    return 0;
}
