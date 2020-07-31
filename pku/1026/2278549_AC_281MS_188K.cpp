#include <stdio.h>
int main(){
	int n , k , pos[201] ;
	while( scanf( "%d" , & n ) && n != 0 )
	{
		for( int i = 1 ; i <= n ; i ++ )
			scanf( "%d" , & pos[i] )  ;
		char * cp = new char[ n + 1 ] ;
		char * res = new char[ n + 1 ] ;
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
			for( int i1 = 1 ; i1 <= n ; i1 ++ )
			{
				int num = 1 , pos1 = i1 ;
				while( pos[ pos1 ] != i1 )
				{
					num ++ ;
					pos1 = pos[ pos1 ] ;
				}
				k1 = k ;
				k1 %= num ;
				pos1 = i1 ;
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