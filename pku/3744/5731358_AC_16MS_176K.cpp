#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std ;

template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)
#define IN(i, s) ( (1<<i) == ((1<<i) & s))


struct Matrix{
    double a[2][2];
    int n, m;
    Matrix(int nn, int mm){ n = nn, m = mm; memset(a, 0, sizeof(a));    }
};
int n;
double p;
int ps[20];

Matrix tmp(2, 2);
Matrix f0(1, 2);

Matrix mull(Matrix A, Matrix B){
    Matrix ret(A.n, B.m);
    REP (i, A.n)
    {
        REP (j, B.m)
        {
            ret.a[i][j] = 0;
            REP (k, B.n)
            {
                ret.a[i][j] += A.a[i][k] * B.a[k][j];
            }
        }
    }
    return ret;
}

Matrix power(Matrix mm, int p){
    if (1 == p) return mm;
    else
    {
        Matrix temp = power(mm, p/2);
        temp = mull(temp, temp);
        if (p&1)
        {
            temp = mull(temp, mm);
        }
        return temp;
    }
}

int main(){
    while (EOF != scanf("%d %lf", &n, &p))
    {
            REP (i, n)  scanf("%d", &ps[i]);

            sort(ps, ps+n);
            tmp.a[0][0] = 0;
            tmp.a[0][1] = (1-p);
            tmp.a[1][0] = 1;
            tmp.a[1][1] = p;

            f0.a[0][0] = 0;
            f0.a[0][1] = 1;

            REP (i, n)
            {
                Matrix mm(2, 2);
                if (0 == i) mm = power(tmp, ps[i]);
                else mm = power(tmp, ps[i] - ps[i-1]);

                f0 = mull(f0, mm);
                f0.a[0][1] -= f0.a[0][0] * p;
                f0.a[0][0] = 0;
                //out(f0.a, f0.n, f0.m);
            }
            printf("%.7lf\n", f0.a[0][1]);
    }
    return 0;
}
