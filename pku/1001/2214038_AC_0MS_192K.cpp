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
		int k1 = d ;
		long int k2 = d ;
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
		if(j + 1 > 4999 - dot)
			{   
				cout << "." ;
				for( int t = 0 ;t < dot + j - 4999 ; t ++ )
					cout << 0 ;
			}
        int te = 4999;
		while( bt[te] == 0 && te > 4999 - dot )
			te-- ; 
		for( int it = j + 1 ; it <= te ; it ++ )		
			if( it == 4999 - dot && te != 4999 - dot )
				cout << bt[it] << "." ;
			else 
				cout << bt[it] ;		
		cout << endl ; 
	}
	return 0 ;
}