// 1125(pku)
// Dijkstra

#include <iostream>
#define INF 0xfffffff

using namespace std ;

int a[101][101], n, num[101] ;
int main(){
	while( 1 == scanf("%d", &n) && n )
	{
		int i, j, v, w, k ;

		for( i = 1; i <= n; i ++ )
			for( j = 1; j <= n; j ++ )
				a[i][j] = INF ;

		for( i = 1; i <= n; i ++ )
		{
			scanf("%d", &num[i]) ;
			for( j = 1; j <= num[i]; j ++ )
			{
				scanf("%d%d", &v, &w) ;
				a[i][v] = w;
			}
			a[i][i] = 0 ;
		}
		// Dijkstra
		for( k = 1; k <= n; k ++ )
			for( i = 1; i <= n; i ++ )
				for( j = 1; j <= n; j ++ )
					if( a[i][k] != INF && INF != a[k][j] )
					{
						if( a[i][j] > a[i][k] + a[k][j] )
							a[i][j] = a[i][k] + a[k][j] ;
					}
		int pos = 0, val = INF, tmp ;
		bool flag ;
		for( i = 1; i <= n; i ++ )
		{
			flag = false ;
			tmp = 0 ;
			for( j = 1; j <= n; j ++ )
			{
				if( tmp < a[i][j] )
					tmp = a[i][j] ;
				if( a[i][j] == INF )
				{
					flag = true ;
					break ;
				}
			}
			if( !flag )
			{
				if( val > tmp )
				{
					pos = i ;
					val = tmp ;
				}
			}
		}
		if( INF == val )
			printf("disjoint\n") ;
		else
			printf("%d %d\n", pos, val) ;
	}
	return 0 ;
}