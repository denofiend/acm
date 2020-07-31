#include <iostream>
using namespace std ;
int Length(int a){
	int k = 0 ;
	while(a / 10 != 0)
	{
		a /= 10 ;
		k ++ ;
	}
	return k + 1 ;
}
int main(){
	double d ;
	int n ;
	while( cin >> d >> n )
	{
		if( n == 1)
		{
			cout << d << endl;
			continue ;
		}
		long int at[5000] , bt[5000] , dot = 0 ;
		if( Length( (int) d) == 1)
		{
			dot = 4 ;
			d *= 10000 ;
		}
		else
		{
			dot = 3 ;
			d *= 1000 ;
		}
		dot *= n ;
		int k1 = d;
		long int k2 = d;
		int i = Length(k1) , j = 4999 , btl = i ;
		while( i > 0)
		{
			bt[j -- ] = k1 % 10 ;
			k1 /= 10 ;
			i -- ;
		}
		while( n -- > 1 )
		{
			k1 = 0 ;
			j = 4999 ;
			j = j - btl + 1 ;
			while( k1 < btl )
			{
				at[k1] = bt[j] ;
				bt[j] = 0 ;
				j ++ ;
				k1 ++ ;
			}
			k1 -- ;
			j = 4999 ;
			while(k1 >= 0)
			{
				bt[j - 1] = ( at[k1] * k2 + bt[j] ) / 10 ;
				bt[j] = ( at[k1] * k2 + bt[j] ) % 10 ;
				j -- ;
				k1 -- ;
			}
			int m = bt[j] ;
			while( m > 0 )
			{
				bt[j --] = m % 10 ;
				m /= 10;
			}
			btl = 4999 - j ;
		}
		if( j + 1 > 4999 - dot)
		{
			cout << "." ;
			for( int s = 0 ; s < j + dot - 4999 ; ++ s)
				cout << 0 ;
			for(int ss = j + 1 ; ss <= 4999 ; ++ ss)
				if(bt[ss] > 0)
					cout << bt[ss] ;
		}
		else
		{
		
			for(int t = j + 1; t <= 4999; ++ t)
			{	
				if( t == 4999 - dot + 1 && bt[t] > 0 )
				{	
					cout << "." ;					
					cout << bt[t] ;
				}
				else if( t > 4999 - dot + 1 && bt[t] > 0 )		
					cout << bt[t] ;	
				else if( t < 4999 - dot + 1 )
					cout << bt[t] ;
			}
		}
		cout << endl ; 
	}
	return 0 ;
}