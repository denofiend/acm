#include <iostream>
#include <algorithm>
using namespace std ;
struct Stick{
		int len ;
		int w;
};
int tail[5001] ;
Stick stick[5001] ;

bool small( Stick & a , Stick & b ){
	if( a.len == b.len )
		return ( a.w < b.w ) ;
	else
		return ( a.len < b.len  ) ;
}

int main(){
	int n , m ;
	cin >> n ;
	while( n -- )
	{
		cin >> m ;
		for( int i = 1 ; i <= m ; ++ i ) 
			cin >> stick[i].len >> stick[i].w ;
		sort( stick + 1, stick + m + 1 , small) ;	
		memset( tail , 0 , sizeof( tail ) );
		tail[1] = 1 ;
		int num = 1 ,j ;
		for( int ii = 2 ; ii <= m ; ++ ii )
		{	
			j = 1 ;
			while( tail[j] )
			{	
				if( stick[ii].len >= stick[ tail[j] ].len && stick[ii].w >= stick[ tail[j] ].w )
				{
					tail[j] = ii ;
					break ;
				}
				++ j ;
			}
			if( !tail[j] )
			{
				tail[j] = ii ;
				++ num ;
			}
		}
		cout << num << endl ;
	}
	return 0 ;
}


