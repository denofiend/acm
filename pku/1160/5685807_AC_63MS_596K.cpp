
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP (i, b)  FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)


#define INF 0x7fffff

int dp[301][301], val[301], cost[301][301], s[301][301] ;


int main(){
    int V, P, mm;
    scanf("%d %d", &V, &P) ;
    int i, j, k;
    for( i = 1; i <= V; i ++ )
    scanf("%d", &val[i]);
    //
    for( i = 1; i <= V; i ++ )
        for( j = i+1; j <= V; j ++ )
        {
            cost[i][j] = 0 ;
            int mid = ( i + j ) / 2 ;
            for( k = i; k <= mid; k ++ )
                cost[i][j] += val[mid] - val[k] ;
            for( ; k <= j; k ++ )
                cost[i][j] += val[k] - val[mid] ;
        }
    //



    for (j = 1; j <= V; ++j)
    {
        dp[1][j] = cost[1][j];
        s[1][j] = j/2 - 1;
        if (0 == s[1][j])   s[1][j] = 1;
    }

    for (i = 2; i <= P; ++i)
        for (j = V; j >= i; j--)
        {
            dp[i][j] = INF;
            mm = j == V ? j : s[i][j+1];
            for (k = s[i-1][j]; k <= mm; ++k)
            {
                if (dp[i-1][k] + cost[k+1][j] < dp[i][j])
                {
                    dp[i][j] = dp[i-1][k] + cost[k+1][j];
                    s[i][j] = k;
                }
            }

        }
   // out(s, P+1, V+1);
    //out(dp, P+1, V+1);
    printf("%d\n", dp[P][V]) ;
    return 0 ;
}
