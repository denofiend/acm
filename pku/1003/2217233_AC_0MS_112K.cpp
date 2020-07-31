#include <iostream>
using namespace std ;
int main(){
	float c ;
	while( cin >> c )
	{
		if( c == 0.00 )
			break ;
		float sum = 0.0 ,num = 0.0 ;
		for( float i = 1.0 ;  ; ++ i )
		{
			num = ( 1.0 / ( i + 1.0 ) ) ;
			if( sum + num < c )
			{
				sum += num;
			}
			else if( sum + num == c )
			{
				cout << (int) i  << " card(s)" << endl ;
				break ;
			}
			else if( sum + num > c )
			{
				cout << (int) i << " card(s)" << endl ;
				break ;
			}
		}
	}
	return 0 ;
}