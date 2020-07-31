// 1163

#include <iostream>

using namespace std ;

int a[100][100], d[100][100] ;
int main(){
	int n, i, j ;
	while( cin >> n )
	{
		for( i = 0; i < n; i ++ )
			for( j = 0; j <= i; j ++ )
				cin >> a[i][j] ;
		d[0][0] = a[0][0] ;
		int max1, max2 = 0;
		for( i = 1; i < n; i ++ )
			for( j = 0; j <= i; j ++ )
			{
				max1 = max2 = 0 ;
				max1 = d[i - 1][j] + a[i][j] ;              // 递推式
				if( j > 0 )
					max2 = d[i - 1][j - 1] + a[i][j] ;      // 递推式
				if( max1 > max2 )
					d[i][j] = max1 ;
				else
					d[i][j] = max2 ;
			}
		int max = d[n - 1][0] ;
		for( i = 1; i < n; i ++ ) 
			if( d[n - 1][i] > max )
				max = d[n - 1][i] ;
		cout << max << endl ;

	}
	return 0 ;
}