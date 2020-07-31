#include <iostream>
using namespace std ;
#define MAX 1500 

int min( int a , int b ){
	return a < b ? a : b ;
}
int main(){
	
	int a[MAX], n , n2 = 0 , n3 = 0 , n5 = 0 ;
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
			++ n2 ;
		if( a[i] == y )
			++ n3 ;
		else if( a[i] == z )
			++ n5 ;
	}
	while( cin >> n )
	{
		if( n == 0 )
			break ;
		cout << a[n - 1] << endl ;
	}
	return 0 ;
}