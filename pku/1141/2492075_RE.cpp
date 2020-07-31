// 1141
// 动态规划


#include <iostream>

#include <string>

using namespace std ;

string s ;
int d[101][101], m[101][101] ;
void print( int i, int j ){
	if( i == j )
	{
		if( '(' == s[i] || ')' == s[i] )
			cout << "()" ;
		else
			cout << "[]" ;
	}
	else if( - 1 == m[i][j] )
	{
		cout << s[i] ;
		print( i + 1, j - 1 ) ;
		cout << s[j] ;
	}
	else if( i < j )
	{
		print( i, m[i][j] ) ;
		print( m[i][j] + 1, j ) ;
	}
}
int main(){
	int i, j, p ;
	while( cin >> s )
	{
		int n = (int)s.size() ;
		
		for( i = n - 1; i >= 0; i -- )
			s[i + 1] = s[i] ;
		s[0] = ' ' ;

		for( i = 1; i <= n; i ++ )
			for( j = 1; j <= n; j ++ )
				d[i][j] = - 1 ;
		// 边界条件
		for( i = 1; i <= n; i ++ )
			d[i][i - 1] = 0 ;
		for( i = 1; i <= n; i ++ )
			d[i][i] = 1, m[i][i] = i ;

		// 状态转移
		for( p = 1 ; p <= n ; p ++ )
		{
			for( i = 1; i <= n - p; i ++ )
			{
				j = i + p ;
				d[i][j] = 0xfffff ;
				if( ( '(' == s[i] && ')' == s[j] ) || ( '[' == s[i] && ']' == s[j] ) ) 
				{
					if( d[i + 1][j - 1] < d[i][j] )
					{
						d[i][j] = d[i + 1][j - 1] ;
						m[i][j] = - 1 ;
					}
				}
			
				if( ( '(' == s[i] ) || ( '[' == s[i] ) )			
				{
					if( d[i + 1][j]  + 1 < d[i][j] )
					{
						d[i][j] = d[i + 1][j] + 1 ;
						m[i][j] = i ;
					}
				}

				if( ( ')' == s[j] ) || ( ']' == s[j] ) ) 
				{
					if( d[i][j - 1] + 1 < d[i][j] )
					{
						d[i][j] = d[i][j - 1] + 1 ;
						m[i][j] = j ;
					}
				}
				
				for( int k = i, q; k < j; k ++ )
				{
					q = d[i][k] + d[k + 1][j] ;
					if( q < d[i][j] )
					{
						d[i][j] = q ;
						if( 0 == q )
							m[i][j] = - 1 ;
						else
							m[i][j] = k ;
					}
				}		
			}	
		}

		print(1, n) ;
		cout << endl ;
	}
	return 0 ;
}
