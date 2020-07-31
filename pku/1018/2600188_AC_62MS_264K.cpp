// 1018

#include <iostream>
#include <algorithm>

using namespace std ;

struct Device{ 
	int W, P ;
} ;

Device de[100][100] ;
int wn[10000], len[100] ;

bool lessthan( const Device & a, const Device & b ){
	return a.W < b.W ;
}
bool lethan( int a, int b ){
	return a < b ;
}
int main(){
	int t, n ;
	cin >> t ;
	while( t -- )
	{
		cin >> n ;
		int i, j, k ;
		for( i = 0, k = 0; i < n; i ++ )
		{
			cin >> len[i] ;
			for( j = 0; j < len[i]; j ++ )
			{	
				cin >> de[i][j].W >> de[i][j].P ;
				wn[k++] = de[i][j].W ;
			}
			sort( &de[i][0], &de[i][ len[i] ], lessthan ) ;
		}
		sort( wn, wn + k, lethan ) ;

		double res = - 1, total = 0.0 ;

		for( i = 0; i < k; i ++ )
		{
			if( wn[i] == wn[i - 1] && i > 0 )
				continue ;
			total = 0.0 ;
			for( j = 0; j < n; j ++ )
			{
				int minprice = 65556 ;
				for( int i1 = 0; i1 < len[j]; i1 ++ )
					if( de[j][i1].W >= wn[i] && minprice > de[j][i1].P )
						minprice = de[j][i1].P ;
				if( minprice <= 0 )
					break ;
				total += minprice ;
			}
			if( j < n )
				continue ;
			if( wn[i] / total > res )
				res = wn[i] / total ;
		}
		printf("%.3lf\n", res) ; 
	}
	return 0 ;
}