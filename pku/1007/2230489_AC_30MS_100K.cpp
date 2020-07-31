#include <iostream>
using namespace std ;
int main(){
	char s[100][50] ;
	int a[100] ;
	int n , m ;
	while( cin >> n >> m )
	{
		for( int i = 0 ; i < m ; ++ i )
			for( int j = 0 ; j < n ; ++ j )
			{
				cin >> s[i][j] ;
				a[i] = 0 ;
			}
		for( int i1 = 0 ; i1 < m ; ++ i1 )
			for( int j1 =0 ; j1 < n ; ++ j1 )
				for( int k = j1 + 1 ; k < n ; ++ k )
					if( s[i1][j1] > s[i1][k] )
						++ a[i1] ;
		int  num = 1 , pos = 0 ;
		while( num <= m )
		{
			for( int j1 = 0 ; j1 < m ; ++ j1 )
				if( a[j1] >= 0 )
				{
					pos = j1 ;
					break ;
				}
			for( int i2 = 0 ; i2 < m ; ++ i2 )
		    	if( a[i2] >= 0 && i2 != pos)
		     		if( a[pos] > a[i2] )
						pos = i2 ;
			for( int i4 = 0 ; i4 < m ; ++ i4 )
				if( a[i4] >= 0 && i4 != pos && a[pos] == a[i4] )
				{
						for( int i3 = 0 ; i3 < n ; ++ i3 )			  
             				cout << s[pos][i3] ;
						cout << endl ;
						a[pos] = - 2 ;
						pos = i4 ;
						++ num ;
				}
			for( int i3 = 0 ; i3 < n ; ++ i3 )			  
				cout << s[pos][i3] ;
			cout << endl ;
			a[pos] = - 2 ;
			++ num ;
		}
	}
	return 0 ;
}