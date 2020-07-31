// 1088(pku)
// 记忆化搜索

#include <iostream>

using namespace std ;

int n, m, f[101][101], a[101][101] ;
bool ok( int x, int y ){
	return x >= 1 && x <= n && y >= 1 && y <= m ;
}
int search( int x, int y ){
	if( f[x][y] > 0 )
		return f[x][y] ;

	if( ok( x - 1, y ) && a[x - 1][y] < a[x][y] && f[x][y] < search( x - 1, y ) + 1 )
		f[x][y] = f[x - 1][y] + 1 ;

	if( ok( x, y + 1 ) && a[x][y + 1] < a[x][y] && f[x][y] < search( x, y + 1 ) + 1 )
		f[x][y] = f[x][y + 1] + 1 ;

	if( ok( x + 1, y ) && a[x + 1][y] < a[x][y] && f[x][y] < search( x + 1, y ) + 1 )
		f[x][y] = f[x + 1][y] + 1 ;

	if( ok( x, y - 1 ) && a[x][y - 1] < a[x][y] && f[x][y] < search( x, y - 1 ) + 1 )
		f[x][y] = f[x][y - 1] + 1 ;

	return f[x][y] ;
}
int main(){
	while( cin >> n >> m )
	{
		memset( f, 0, sizeof( f ) ) ;
		int i, j ;
		for( i = 1; i <= n; i ++ )
			for( j = 1; j <= m; j ++ )
				cin >> a[i][j] ;

		int max = - 1 ;
		for( i = 1; i <= n; i ++ )
			for( j = 1; j <= m; j ++ )
				if( max < search(i, j) )
					max = search(i, j) ;
		cout << max + 1 << endl ;
	}
	return 0 ;
}