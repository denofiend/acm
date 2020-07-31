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

int g[16][330];
int cnt[301];
int n, m;

bool dfs(int p){
    if (p == n)
    {
        REP (i, m)
        {
            if (1 != cnt[i])    return false;
        }
        return true;
    }
    if (dfs(p+1))   return true;

    int flag = 0;
    FOR (i, 1, g[p][0]+1)
    {
        if (cnt[ g[p][i] ]) flag = 1;
        cnt[ g[p][i] ]++;
    }
    if (flag)
    {
        FOR (i, 1, g[p][0]+1)
        {
            cnt[ g[p][i] ] --;
        }
        return false;
    }
    if (dfs(p+1))   return true;

    FOR (i, 1, g[p][0]+1)
    {
        cnt[ g[p][i] ] --;
    }
    return false;

}

int main(){
    int mm;
    while (EOF != scanf("%d %d", &n, &m))
    {
        REP (i, n)  g[i][0] = 0;

        REP (i, n)
        {
            REP (j, m)
            {
                scanf("%d", &mm);
                if (1 == mm)
                {
                    g[i][ ++g[i][0] ] = j;
                    cnt[j]++;
                }

            }
        }
        REP (j, m)  cnt[j] = 0;
        if (dfs(0)) printf("Yes, I found it\n");
        else printf("It is impossible\n");
    }
    return 0;
}
