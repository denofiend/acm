
// 1014

#include <iostream>

using namespace std ; 

int a[7] ;
bool find( int ans, int sum, int end ){
	if( ans == sum )
		return true ;
	if( ans < sum )
		return false ;
	for( int i = end; i > 0; i -- )
	{
		if( a[i] > 0 )
		{
			a[i] -- ;
			if(	find( ans, sum + i, i ) )
				return true ;
			a[i] ++ ;
		}
	}
	return false ;
}
int main(){
	int k  = 1;
	while( 1)
	{
		int sum = 0 ;
		for( int i = 1; i < 7; i ++ )
		{
			cin >> a[i] ;
			if( a[i] > 6 )
				a[i] = 6 + a[i] % 2 ;
			sum += a[i] * i ;
		}
		sum /= 2 ;
		if( 0 == sum )
			break ;
		cout << "Collection #" << k ++ << ":" << endl ;
		if( 1 == sum % 2 )
			cout << "Can't be divided." << endl ;
		else
		{
			if( find( sum, 0, 6 ) )
				cout << "Can be divided." << endl ;
			else
				cout << "Can't be divided." << endl ;
		}
	}
	return 0 ;
}