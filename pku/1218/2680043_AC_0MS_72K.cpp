// 1218(pku)
// 无聊

#include <stdio.h>
#include <string.h>

int main(){
	int t, n, i, j, person[101], num, k ;
	scanf("%d", &t) ;
	while( t -- )
	{
		scanf("%d", &n) ;
		memset( person, 0, sizeof( person ) ) ;
		for( i = 2; i <= n; i ++ )
			for( j = i, k = 1; j <= n; j ++ )
				if( 0 == j % i )
					person[j] ^= 1 ;	
		num = 0 ;
		for( i = 1; i <= n; i ++ )
			if( 0 == person[i] )
				num ++ ;
		printf("%d\n", num) ;
	}
	return 0 ;
}