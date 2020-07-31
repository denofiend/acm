// 1251

#include <iostream>

using namespace std ;

int map[27][27], n, find[27] ;
bool flag[27] ;
int prim(){
	memset( find, 0, sizeof( find ) ) ;
	memset( flag, false, sizeof( flag) ) ;
	
	int dist = 0, i = 1, j = 1, k = 2, min, index ;
	
	find[1] = 1 ;
	flag[1] = true ;

	while( k <= n )
	{
		min = 0xffffff ;
		for( i = 1; i <= k; i ++ )
			for( j = 2; j <= n; j ++ )
				if( !flag[j] && find[i] && min > map[ find[i] ][j] )
				{
					min = map[ find[i] ][j] ;
					index = j ;
				}
		find[k ++] = index ;
		flag[index] = true ;
		dist += min ;
	}
	return dist ;

}
int main(){
	while( cin >> n && n )
	{

		char c, c1 ;
		int num, val, i, j ;
		for( i = 1; i <= n; i ++ )
			for( j = 1; j <= n; j ++ )
				map[i][j] = 0xffffff ;

		for( i = 1; i < n; i ++ )
		{
			cin >> c >> num ;
			for( j = 1; j <= num; j ++ )
			{
				cin >> c1 >> val ;
				map[ c - 64 ][ c1 - 64 ] = val ;
				map[ c1 - 64 ][ c - 64 ] = val ;
			}

		}
		cout << prim() << endl ;
	}
	return 0 ;
}