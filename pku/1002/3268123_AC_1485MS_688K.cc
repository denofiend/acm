//================
// pku 1002
// zab08
// Rabin-Karp 算法
// 将字符转化成
// 整数比较大小
//
//---------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char  c ;
int n , i = 0 ,j = 0 , k = 1 , num = 1 , res[100000] , E = 1000000 , num1 = 0 ;
int comp(const void *a,const void *b ){
	return *(int *) a - *(int * ) b;
}
int main(){
	memset( res , 0 , sizeof( res ) ) ;
    scanf( "%d", & n ) ;
	while ( 1 == scanf( "%c",& c ) )
	{
		if ( c == '-' || c == '\n' )
			continue ;
		else
		{
			if ( c == 'A' || c == 'B' || c == 'C' )
				c = '2' ;
			else if ( c == 'D' || c == 'E' || c == 'F' )
				c = '3' ;
			else if ( c == 'G' || c == 'H' || c == 'I' )
				c = '4' ;
			else if ( c == 'J' || c == 'K' || c == 'L' )
				c = '5' ;
			else if ( c == 'M' || c == 'N' || c == 'O' )
				c = '6' ;
			else if ( c == 'P' || c == 'R' || c == 'S' )
				c = '7' ;
			else if ( c == 'T' || c == 'U' || c == 'V' )
				c = '8' ;
			else if ( c == 'W' || c == 'X' || c == 'Y' )
				c = '9' ;
			// 转化成整数
			res[i] = res[i] * 10 + c - '0' ;
			j ++ ;
			if ( j == 7 )
				i ++ , j = 0 ;
			if ( i == n + 1 )
				break ;
		}
	}
	qsort( res, n, sizeof(int), comp );
	for ( i = 0 ,k = 1 ; i < n  ; )
	{
		if ( res[i] == res[k] )
			k ++ , num ++ ;
		else if ( res[i] != res[k] )
		{
			if ( 1 == num )
				num1 ++ ;
			if ( num > 1 )
			{
				for ( j = 0 ; j < 3 ; j ++ )
				{
					
					printf("%d", res[i] / E ) ;
					res[i] -= ( res[i] / E ) * E , E /= 10 ;
				}
				printf("-") ;
				for ( j = 3 ; j < 7 ; j ++ )
				{
					printf("%d",res[i] / E ) ;
					res[i] -= ( res[i] / E ) * E , E /= 10 ;
				}
				printf(" %d\n",num) ;
			}
			i = k ++ ;
			num = 1 , E = 1000000 ;
		}
	}
	if ( num1 == n )
		printf("No duplicates.\n") ;
	return 0 ;
}

