#include <iostream>
using namespace std ;
int min( int a , int b ){
	if( a < b )
		return a ;
	else
		return b ;
}
int main(){
	const int MAX = 1500 ;
	int a[MAX] , n , n2 = 0 , n3 = 0 , n5 = 0 ;
	a[0] = 1 ;
	int  x , y , z ;
	for( int i = 1 ; i < MAX; ++ i )
	{
		x = a[n2] * 2 ;
		y = a[n3] * 3 ;
		z = a[n5] * 5 ;
		a[i] = min( x , y ) ;
		a[i] = min( a[i] , z ) ;
		if( a[i] == x )
		{
			++ n2 ;
			while( a[n2] * 2 == y || a[n2] * 2 == z )
				++ n2 ;
		}
		else if( a[i] == y )
		{
			++ n3 ;
			while( a[n3] * 3 == x || a[n2] * 3 == z )
				++ n3 ;
		}
		else if( a[i] == z )
		{
			++ n5 ;
			while( a[n5] * 5 == x || a[n5] * 5 == y )
				++ n5 ;
		}
	}
	while( cin >> n )
	{
		if( n == 0 )
			break ;
		cout << a[n - 1] << endl ;
	}
	return 0 ;
}