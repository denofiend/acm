// 1160(pku)
// 区间DP

#include <stdio.h>
#define INF 0xfffffff

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

	dp[0][0] = 0 ;
	for( i = 0; i < P; i ++ )
		for( j = 0; j <= V; j ++ )
		{
			if( dp[i][j] < INF )
			{
				// 状态转移方程 dp[i + 1][j + k] = Min( dp[i + 1][j + 1], dp[i][j] + cost[j + 1][j + k] );
				for( k = 1; j + k <= V; k ++ )
					if( dp[i + 1][j + k] > dp[i][j] + cost[j + 1][j + k] )
						dp[i + 1][j + k] = dp[i][j] + cost[j + 1][j + k] ;
			}
		}
	printf("%d\n", dp[P][V]) ;
	return 0 ;
}