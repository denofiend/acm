///



#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>


using namespace std;

template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP (i, b)  FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)


#define INF 0x7fffff

int dp[301][301], val[301], cost[301][301] ;


int main(){
    int V, P ;
    scanf("%d %d", &V, &P) ;
    int i, j, k;
    for( i = 1; i <= V; i ++ )
    scanf("%d", &val[i]);
    //
    for( i = 1; i <= V; i ++ )
        for( j = i; j <= V; j ++ )
        {
            cost[i][j] = 0 ;
            int mid = ( i + j ) / 2 ;
            for( k = i; k <= mid; k ++ )
                cost[i][j] += val[mid] - val[k] ;
            for( ; k <= j; k ++ )
                cost[i][j] += val[k] - val[mid] ;
        }
    //
    for( i = 0; i <= P; i ++ )
        for( j = 0; j <= V; j ++ )
            dp[i][j] = INF ;


    dp[0][0] = 0;

    for( i = 1; i <= P; i ++ )
        for( j = 1; j <= V; j ++ )
        {
                for( k = i-1; k < j; ++k)
                {

                    if (dp[i-1][k] + cost[k+1][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i-1][k] + cost[k+1][j];
                    }
                }
        }
    printf("%d\n", dp[P][V]) ;
    return 0 ;
}

