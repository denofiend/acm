// 1141
// 动态规划


#include <iostream>
#include <string>


using namespace std ;

inline int MIN( int x, int y ){
	return x <= y ? x : y ;
}

int main(){
	string s ;
	int i, j, d[101][101], p ;
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
			d[i][i] = 1 ;

		// 状态转移
		for( p = 1 ; p <= n ; p ++ )
		{

			for( i = 1; i <= n - p; i ++ )
			{
				j = i + p ;
				d[i][j] = 0xfffff ;
				if( ( '(' == s[i] && ')' == s[j] ) || ( '[' == s[i] && ']' == s[j] ) ) 
					d[i][j] = MIN( d[i][j], d[i + 1][j - 1] ) ;
			
				if( ( '(' == s[i] ) || ( '[' == s[i] ) )			
					d[i][j] = MIN( d[i][j], d[i + 1][j] + 1 ) ;

				if( ( ')' == s[j] ) || ( ']' == s[j] ) ) 
					d[i][j] = MIN( d[i][j], d[i][ j - 1] + 1 ) ;
				
				for( int k = i; k < j; k ++ )
					d[i][j] = MIN( d[i][j], d[i][k] + d[k + 1][j] ) ;
			}	
		}

		int num = d[1][n] ;
		for( i = 2; i <= n; i ++ )
		{
			if( d[i][n] < d[1][n] && num )
			{
				if( '(' == s[i - 1] || ')' == s[i - 1] )
					cout << "()" ;
				else if( '[' == s[i - 1] || ']' == s[i - 1] )
					cout << "[]" ;
				num -- ;
			}
			else
				cout << s[i - 1] ;
		}
		if( 1 == num )
		{
			if( '(' == s[n] || ')' == s[n] )
				cout << "()" ;
			else if( '[' == s[n] || ']' == s[n] )
				cout << "[]" ;
		}
		else
			cout << s[n] ;
		cout << endl ;
		//for( int i = 1 ; i <= n; i ++ )
		//{
		//	for( j = 1; j <= n; j ++ )
		//		cout << d[i][j] << " " ;
		//	cout << endl ;
		//}
		//cout << endl ;
	}
	return 0 ;
}