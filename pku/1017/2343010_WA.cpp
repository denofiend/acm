#include <iostream>
using namespace std ;
int main(){
	int a[6], i = 0, sum = 0 ;
	while( cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] )
	{
		if( a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 )
			break ;
		sum = 0 ;
		for( i = 0; i < 6; i ++ )
			sum += ( i + 1 ) * ( i + 1 ) * a[i] ;
		if( sum % 36 == 0 )
			cout << sum / 36 << endl ;
		else 
			cout << sum / 36 + 1 << endl ;
	}
	return 0 ;
}