// 1127 (pku)
// 判断线段是否相连
// 计算几何中的叉积的应用

#include <iostream>
using namespace std ;
#define MAX(a, b) ( a >= b ? a : b )
#define MIN(a, b) ( a <= b ? a : b ) 


int t ;
int connect[13];
struct Point{
	int x, y ;
} ;
struct Straw{
	Point sta, end ;
} ;
Straw straw[13] ;

// Direction function
int Direction( const Point pi, const Point pj, const Point pk ){ 
	return ( ( pk.x - pi.x ) * ( pj.y - pi.y ) - ( pj.x - pi.x ) * ( pk.y - pi.y ) ) ;
}
// Onsegment function
bool OnSegment( const Point pi, const Point pj, const Point pk ){
	if( ( MIN( pi.x, pj.x ) <= pk.x  &&  pk.x <= MAX( pi.x, pj.x ) )  && ( MIN( pi.y, pj.y ) <= pk.y && pk.y <= MAX( pi.y, pj.y ) ) )
		return true ;
	else
		return false ;
}
// Connected function
bool Connected( const int & a, const int & b ){

		int d1 = Direction( straw[a].sta, straw[a].end, straw[b].sta ) ;

		int d2 = Direction( straw[a].sta, straw[a].end, straw[b].end ) ;

		int d3 = Direction( straw[b].sta, straw[b].end, straw[a].sta ) ;
		
		int d4 = Direction( straw[b].sta, straw[b].end, straw[a].end ) ;

		if( ( d1 * d2 < 0 ) && ( d3 * d4 < 0 ) )
			return true ;
		else if( 0 == d1 && OnSegment( straw[a].sta, straw[a].end, straw[b].sta ) )
			return true ;
		else if( 0 == d2 && OnSegment( straw[a].sta, straw[a].end, straw[b].end ) )
			return true ;

		else if( 0 == d3 && OnSegment( straw[b].sta, straw[b].end, straw[a].sta ) ) 
			return true ;
		else if( 0 == d4 && OnSegment( straw[b].sta, straw[b].end, straw[a].end ) )
			return true ;
		else
			return false ;
}


int main(){

	while( cin >> t && t )
	{
		for( int i = 1; i <= t; i ++ )
		{
			connect[i] = i ;
			cin >> straw[i].sta.x >> straw[i].sta.y >> straw[i].end.x >> straw[i].end.y ;
		}
		//　判断线段是否相连
		for( int i1 = 1; i1 < t; i1 ++ )
			for( int j1 = i1 + 1; j1 <= t; j1 ++ )
				if( ( connect[i1] != connect[j1] ) && Connected(i1, j1) )
				{
					int a = connect[i1], b = connect[j1] ;
					for( int k = 1; k <= t; k ++ )
						if( a == connect[k] )
							connect[k] = b ;
				}
		int straw1, straw2 ;
		while( cin >>  straw1 >> straw2 )
		{
			if( 0 == straw1 && 0 == straw2 )
				break ;
			if( connect[straw1] == connect[straw2] )
				cout << "CONNECTED" << endl ;
			else
				cout << "NOT CONNECTED" << endl ;
		}
	}
	return 0 ;
}