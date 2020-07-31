#include <iostream>
using namespace std ; 
int main(){
	int len ,a[101][101] ,b[101];
	cin >> len ;
	for( int i = 1 ; i <= len ; ++ i)
		for( int j = 1 ; j <= len ; ++ j )
			cin >> a[i][j] ;
	int sum = 0 ;
	for( int i1 = 1 ;i1 <= len ; ++ i1 )
	{
		for( int j1 = 1 ; j1 <= len ; ++ j1 )
			b[j1] = 0 ;
		for( int j2 = i1 ; j2 <= len ; ++ j2 )
		{
			for( int k = 1; k <= len ; ++ k )
				b[k] += a[j2][k] ;
			int sum1 = 0 , bb = 0 ;
			for( int i3 = 1; i3 <= len ; ++ i3 )
			{
				if( bb > 0 )
					bb += b[i3] ;
				else
					bb = b[i3] ;
				if( bb > sum1 )
					sum1 = bb ;
			}
			if( sum < sum1 )
				sum = sum1 ;
		}
	}	
	cout << sum << endl ;
		
	return 0 ;
}