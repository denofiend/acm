// 1036(pku)

#define OUT(x) (cout << #x << " = " << x << endl)
#define MAXN 110
#include <iostream>
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i++)	out(x[i], m);	cout << endl;	}


int N, K, T;
struct Node{
    int t, p, s;
};

Node gangsters[MAXN];
int f[MAXN];

int main(){
    int i, state;
    while (EOF != scanf("%d %d %d", &N, &K, &T))
    {
        for (i = 0; i < N; i++)
            scanf("%d", &gangsters[i].t);
        for (i = 0; i < N; i++)
            scanf("%d", &gangsters[i].p);
        for (i = 0; i < N; i++)
            scanf("%d", &gangsters[i].s);
        memset(f, 0, sizeof(f));
        int ans = 0, maxT, maxP, maxp;
        for (state = 1; state <= K; state++)
        {
            maxP = -1;
            for (i = 0; i < N; i++)
            {
                if (gangsters[i].t <= T && gangsters[i].s == state && (maxP < gangsters[i].p || maxP == gangsters[i].p && maxT < gangsters[i].t))
                {
                    maxP = gangsters[i].p;
                    maxT = gangsters[i].t;
                    maxp = i;
                }
            }
            if (-1 == maxP)  continue;

            maxP = 0;
            for (i = 0; i < N; i++)
            {
                if (i == maxp)  continue;
                if (gangsters[i].t <= T && gangsters[i].s < state && maxP < f[gangsters[i].s] && gangsters[i].t < gangsters[maxp].t - 1)    maxP = f[gangsters[i].s];
            }

            maxP += gangsters[maxp].p;
            f[state] = maxP;
            if (maxP > ans) ans = maxP;
        }
        printf("%d\n", ans);
    }
	return 0;
}
