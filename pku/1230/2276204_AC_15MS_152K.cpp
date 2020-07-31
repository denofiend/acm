#include <iostream>
using namespace std ;
int main(){
	int t , n , k ;
	struct Wall{
		int sta_x , sta_y , end_x , end_y ;
	};
	Wall wall[101] ;                  
	cin >> t ;
	while( t -- )
	{
		cin >> n >> k ;
		memset( wall , 0 , sizeof( wall ) ) ;
		int max_y = 0 ;
		for( int i = 0 ; i < n ; i ++ )
		{
			cin >> wall[i].sta_y >> wall[i].sta_x >> wall[i].end_y >> wall[i].end_x ;
			if( wall[i].sta_y > wall[i].end_y )
				swap( wall[i].sta_y , wall[i].end_y ) ;
			if( wall[i].end_y > max_y )
				max_y = wall[i].end_y ;
		}
		int k_sum = 0 , num = 0 , sort[101] ;       //sort[101]是一列中所有墙的最右下标的集合
		for( int j = 0 ; j <= max_y ; j ++ )
		{
			k_sum = 0 ;
			memset( sort , 0 , sizeof( sort ) ) ;
			for( int i1 = 0 ; i1 < n ; i1 ++ )
				if( wall[i1].sta_y <= j && wall[i1].end_y >= j )
				{
					k_sum ++ ;
					sort[i1] = wall[i1].end_y ;
				}
			if( k_sum > k )
			{
				for( int i2 = 0 ; i2 < k_sum - k ; i2 ++ )
				{
					int max_id = 0 ;
					for( int i3 = 1 ; i3 < n ; i3 ++ )
						if( sort[i3] > sort[ max_id ] )
							max_id = i3 ;
					wall[ max_id ].sta_x = wall[ max_id ]. end_x = wall[ max_id ].sta_y = wall[ max_id ].end_y = 0 ;
					sort[ max_id] = 0 ;
					num ++ ;
				}
			}
		}
		cout << num << endl ;
	}
	return 0 ;
}