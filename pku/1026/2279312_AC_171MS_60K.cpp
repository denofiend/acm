//==============
//  pku(1026)
//   交换群
//============
#include <stdio.h>
int main(){
	int n , k , pos[201] ;
	char cp[201] , res[201] ;
	while( scanf( "%d" , & n ) && n != 0 )
	{
		for( int i = 1 ; i <= n ; i ++ )
			scanf( "%d" , & pos[i] )  ;
		while( scanf( "%d" , & k ) && k != 0 )
		{
			for( int j = 0 ; j < n ; j ++ )
				cp[j] = res[j] = ' ' ;
			char c ;
			int j1 = 1 ;
			scanf("%c" , & c ) ;
    		while( scanf("%c" , & c ) && c != '\n' )
			{
				cp[j1] = c ;
				j1 ++ ;
			}
			while( j1 <= n )
			{
				cp[j1] = ' ' ;
				j1 ++ ;
			}
			int k1 = k ;
			for( int i1 = 1 ; i1 <= n ; i1 ++ )      //num用来记录几次置换后能变成原来的元素
			{
				int num = 1 , pos1 = i1 ;
				while( pos[ pos1 ] != i1 )
				{
					num ++ ;
					pos1 = pos[ pos1 ] ;
				}
				k1 = k ;
				k1 %= num ;                           // k1 % num 后的 k1 为这个元素置换的次数
				pos1 = i1 ;                          // pos1 用来找到这个元素置换k1次后的位置
				while( k1 --)
					pos1 = pos[ pos1 ] ;
				res[pos1] = cp[i1] ;
			}
			for( int i3 = 1 ; i3 <= n ; i3 ++ )
				printf( "%c" , res[i3] ) ;
			printf( "\n" ) ;
		}
		printf( "\n" ) ;
	}
	return 0 ;
} 