//
//
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 105;
int N, K, T;

struct Gangster{
    int t, p, s;
    bool operator < (const Gangster &bj) const{
        return t > bj.t;
    }
};

Gangster gang[maxn];
int f[maxn];

void input(){
    int i;
    for (i = 1; i <= N; i++)
        scanf("%d", &gang[i].t);
    for (i = 1; i <= N; i++)
        scanf("%d", &gang[i].p);
    for (i = 1; i <= N; i++)
        scanf("%d", &gang[i].s);
}

void dp(){
    memset(f, 0xff, sizeof(f));
    sort(&gang[1], &gang[N+1]);
    int i, j, maxi;
    for (i = 1; i <= N; i++)
        if (gang[i].t >= gang[i].s)
            f[i] = gang[i].p;

   for (i = 1; i <= N; i++)
   {
        maxi = -1;
        for (j = 1; j < i; j++)
        {
            if ((gang[j].t - gang[i].t) >= abs(gang[j].s - gang[i].s) && f[j] > maxi )
                maxi = f[j];
        }
        if (maxi !=-1)
        {
            if (f[i]==-1 ) f[i] = maxi ;
            else f[i] += maxi;
        }
    }
    int ans = *max_element(&f[1], &f[N+1]);
    if (-1 == ans) ans = 0;
    printf("%d\n", ans);
}

int main(){
    while (EOF != scanf("%d%d%d", &N, &K, &T))
    {
        input();
        dp();
    }
    return 0;
}
