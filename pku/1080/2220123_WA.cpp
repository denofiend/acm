#include <stdio.h>
#define MAX 5000
int ma[5][5] = {5 , - 1 , - 2 , - 1 , - 3 ,- 1 , 5 , - 3 , - 2 , - 4 ,- 2 , - 3 , 5 , - 2 , - 2 ,- 1 , - 2 , - 2 , 5 ,- 1 ,- 3 , - 4 , - 2 , - 1 , - 500} ;
int n ,len1 , len2 , arr[MAX] , brr[MAX] ;
long cal[MAX][MAX] ;
char s1[MAX] , s2[MAX] ;
int max( int a , int b ){
	if( a > b )
		return a ;
	else
		return b ;
}
int main(){
	scanf( "%d" , & n );
	while( n -- )
	{	
		scanf("%d %s", &len1 , s1 );
		scanf("%d %s",& len2 , s2 );
		for( int i = 0 ;i < len1 ; ++ i )
		{
			switch( s1[i] )
			{
             	case 'A' : arr[i + 1] = 0 ; break ;
		    	case 'C' : arr[i + 1] = 1 ; break ;
		    	case 'G' : arr[i + 1] = 2 ; break ;
		    	case 'T' : arr[i + 1] = 3 ; break ;
				case '-' : arr[i + 1] = 4 ; break ;
			}
		}
		for( int j = 0 ; j < len2 ; ++ j )
		{
			switch( s2[j] )
			{
	    		case 'A' : brr[j + 1] = 0 ; break ;
	     		case 'C' : brr[j + 1] = 1 ; break ;
	    		case 'G' : brr[j + 1] = 2 ; break ;
		    	case 'T' : brr[j + 1] = 3 ; break ;
				case '-' : brr[j + 1] = 4 ; break ;
			}
		}
		for( int i1 = 1 ; i1 <= len1 ; ++ i1 )
			cal[i1][0] = ma[ arr[i1]][4] ;
		for( int i2 = 1 ; i2 <= len2 ; ++ i2 )
			cal[0][i2] = ma[4][brr[i2] ];
		cal[0][0] = 0 ; 
		for( int ii = 1 ; ii <= len1 ; ++ ii )
			for( int jj = 1; jj <= len2 ; ++ jj )
			{
				cal[ii][jj] = -200 ;
				cal[ii][jj] = max ( cal[ii][jj] , cal[ii - 1][jj - 1] + ma[ arr[ii] ][ brr[jj] ] ) ; 
				cal[ii][jj] = max ( cal[ii][jj] , cal[ii - 1][jj] + ma[ arr[ii] ][4] );
				cal[ii][jj] = max ( cal[ii][jj] , cal[ii][jj - 1] + ma[4][ brr[jj] ] );
			}
		printf("%ld\n" , cal[len1][len2] );
	}
	return 0 ;
}