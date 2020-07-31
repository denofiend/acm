#include <stdio.h>
#include <string.h>

char s[101] ;

int d[101][101] ;

void print( int i, int j ){
	if( i > j )
		return ;
	else if( i == j )
	{
		if( '(' == s[i] || ')' == s[i] )
			printf("()") ;
		else
			printf("[]") ;
	}
	else
	{

		for( int k = i; k < j; k ++ )
		{
			if( d[i][j] == d[i][k] + d[k + 1][j] )
			{
				print( i, k ) ;
				print( k + 1, j ) ;
				return ;
			}
		}

		printf("%c", s[i]) ;
		print( i + 1, j - 1 ) ;
		printf("%c", s[j]) ;
	}
}
int main(){
	int i, j, p, q, k, n ;
	while( gets( s ) )
	{

		n = strlen(s);
		
		for( i = n - 1; i >= 0; i -- )
			s[i + 1] = s[i] ;
		s[0] = ' ' ;

		for( i = 1; i <= n; i ++ )
			d[i][i - 1] = 0 ;
		for( i = 1; i <= n; i ++ )
			d[i][i] = 1 ;

		for( p = 1 ; p <= n ; p ++ )
		{
			for( i = 1; i <= n - p; i ++ )
			{
				j = i + p ;
				d[i][j] = 0xffffff ;
				if( ( '(' == s[i] && ')' == s[j] ) || ( '[' == s[i] && ']' == s[j] ) ) 
				{
					if( d[i + 1][j - 1] < d[i][j] )
						d[i][j] = d[i + 1][j - 1] ;
				}
				/*
				if( ( '(' == s[i] ) || ( '[' == s[i] ) )			
				{
					if( d[i + 1][j]  + 1 < d[i][j] )
						d[i][j] = d[i + 1][j] + 1 ;
				}

				if( ( ')' == s[j] ) || ( ']' == s[j] ) ) 
				{
					if( d[i][j - 1] + 1 < d[i][j] )
						d[i][j] = d[i][j - 1] + 1 ;
				}
				*/
				for( k = i; k < j; k ++ )
				{
					q = d[i][k] + d[k + 1][j] ;
					if( q < d[i][j] )
						d[i][j] = q ;
				}		
			}	
		}

		print(1, n) ;
		printf("\n") ;
	}
	return 0 ;
}
