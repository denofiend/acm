#include <iostream>
using namespace std;
#define MAX 200
int ma[5][5] = {5 , - 1 , - 2 , - 1 , - 3 ,- 1 , 5 , - 3 , - 2 , - 4 ,- 2 , - 3 , 5 , - 2 , - 2 ,- 1 , - 2 , - 2 , 5 ,- 1 ,- 3 , - 4 , - 2 , - 1 , -200} ;
int n ,len1 , len2 , arr[MAX] , brr[MAX] ;
int  cal[MAX][MAX] ;
char s1[MAX] , s2[MAX] ;
int  max( int  a , int  b ){
	if( a > b )
		return a ;
	else
		return b ;
}
int main(){
	cin >> n ;
	while( n -- )
	{	
		cin >> len1 >> s1 >> len2 >> s2 ;
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
		 
		for( int ii = 0 ; ii <= len1 ; ++ ii )
			for( int jj = 0; jj <= len2 ; ++ jj )
			{
				if( ii == 0 && jj == 0 )
					cal[ii][jj] = 0 ;
				else if( ii == 0 )
					cal[ii][jj] = cal[ii][jj-1]+ ma[4][ brr[jj] ] ;
				else if( jj == 0 )
					cal[ii][jj] = cal[ii-1][jj]+ ma[ arr[ii]][4] ;
				else
				{
					cal[ii][jj] = -200 ;
		    		cal[ii][jj] = max ( cal[ii][jj] , cal[ii - 1][jj - 1] + ma[ arr[ii] ][ brr[jj]] ) ; 
		     		cal[ii][jj] = max ( cal[ii][jj] , cal[ii][jj - 1] + ma[4][brr[jj]] );
		    		cal[ii][jj] = max ( cal[ii][jj] , cal[ii - 1][jj] + ma[ arr[ii]][4] );
				}
			}
		cout << cal[len1][len2] << endl ;
	}
	return 0 ;
}