#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *a,const void *b ){
	return strcmp((char *)a,(char *)b);
}
int main(){
	char tel[100000][7] , c ;
	int n , i = 0 ,j = 0 , num = 1 , k , ii , num1 = 0 ;
    scanf( "%d", & n ) ;
	while( scanf( "%c",& c ) == 1 )
	{
		if( c == '-' || c == '\n' )
			continue ;
		else
		{
			if( c == 'A' || c == 'B' || c == 'C' )
				c = '2' ;
			else if( c == 'D' || c == 'E' || c == 'F' )
				c = '3' ;
			else if( c == 'G' || c == 'H' || c == 'I' )
				c = '4' ;
			else if( c == 'J' || c == 'K' || c == 'L' )
				c = '5' ;
			else if( c == 'M' || c == 'N' || c == 'O' )
				c = '6' ;
			else if( c == 'P' || c == 'R' || c == 'S' )
				c = '7' ;
			else if( c == 'T' || c == 'U' || c == 'V' )
				c = '8' ;
			else if( c == 'W' || c == 'X' || c == 'Y' )
				c = '9' ;
			tel[i][j++] = c ;
			if( j == 7 )
				i ++ , j = 0 ;
			if( i == n + 1 ) 
				break ;
		}
	}
	qsort(tel, n, sizeof(char) * 7, comp);
	for( j = 0 , k = 1 ; j < n && k <= n ; )
	{
		for( i = 0 ; i < 7 ; i ++ )
		{

			if( tel[j][i] != tel[k][i] )
			{
				if( num == 1 )
					num1 ++ ;
				if( num > 1 && num < n )
				{
					for( ii = 0 ; ii < 3 ;ii ++ )
						printf("%c",tel[j][ii]) ;
					printf("-") ;
					for(ii = 3 ; ii < 7 ;ii ++ )
						printf("%c",tel[j][ii]);
					printf(" %d\n", num ) ;
					num = 1 ; 
				}

				j = k ++ ;
				break ;
			}
			if( i == 6 )
				num ++ , k ++ ;
		}
	}
	if( num1 == n )
		printf("No duplicates.\n") ;
	return 0 ;
}
