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

int main(){
    int n, m, mm, ok, flag;
    while (EOF != scanf("%d %d", &n, &m))
    {
        REP (i, n)  g[i][0] = 0;
        REP (j, m)  cnt[j] = 0;
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
        ok = 1;
        REP (j, m)
        {
            if (0 == cnt[j])
            {
                ok = 0;
                break;
            }
        }
        if (0 == ok)
        {
            printf("It is impossible\n");
            continue;
        }
        mm = 1<<n;
        FOR (s, 1, mm)
        {
            REP (j, m)  cnt[j] = 0;
            flag = 0;
            REP (i, n)
            {
                if (IN(i, s))
                {
                    FOR (j, 1, g[i][0]+1)
                    {
                        if (1 == cnt[ g[i][j] ])
                        {
                            flag =1;
                            break;
                        }
                        else cnt[g[i][j]]++;
                    }

                }
                if (flag)   break;
            }
            if (flag)   continue;
            ok = 1;
            REP (j, m)
                if (1 != cnt[j])
                {
                    ok = 0;
                    break;
                }
            if (1 == ok)    break;
        }
        if (ok) printf("Yes, I found it\n");
        else printf("It is impossible\n");
    }
    return 0;
}
