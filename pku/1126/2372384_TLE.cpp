// 1126 pku
// 正则表达式

#include <stdio.h>
int main(){
	char c ;
	int cnum = 1;
	while( 1 ) 
	{
		switch( c = getchar() )
		{
			case 'C' :
			case 'D' :
			case 'E' :
			case 'I' :
				{
					if( cnum ) cnum ++ ;
					break ;
				}
			case 'N' :
				if( !cnum )
				{
					while( '\n' != getchar() ) ;
					printf("NO\n") ;
					break ;
				}
			case '\n' :
				if( cnum )
				{
					printf("NO\n") ;
					cnum = 1 ;
					break ;
				}
				else
				{
					printf("YES\n") ;
					cnum = 1; 
					break ;
				}
			case EOF :
				return 0 ;
			default :
				if( c < 'p' || c > 'z' || ! cnum )
				{
	        		while( '\n' != getchar() ) ;
	        		printf("NO\n") ;
					cnum = 1 ;
				 }
				else
					cnum -- ;
		}
	}
}