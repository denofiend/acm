#include <iostream>
using namespace std ;
int main(){
	int sum , num = 0 , path[100] , i = 0 , sum1 = 0 , num1 = 0 ;
	bool flag = false ;
	char c1 ;
	while( cin >> sum )
	{
		memset( path , 0 , sizeof( path ) ) ;
		while( cin >> c1 )
		{
			if( c1 == ')' )
			{	
				-- i ;
				if( 2 == num )
				{	
					if( sum1 == sum )
						++ num1 ;
					sum1 -= path[ i + 1] ;
					path[ i+ 1 ] = 0 ;
					num = 0 ;
				}
				if( !flag )
				{
					sum1 -= path[i + 1] ;
					path[ i + 1 ] = 0 ;
				}
				flag = false ;
				if( i == 0 )
				{
					if( num1 >= 1 )
						cout << "yes" << endl ;
					else 
						cout << "no" << endl ;
					num = 0 ;
					num1 = 0;
					sum1 = 0 ;
					break ;
				}
				else 
					continue ;
			}
		    else if( c1 == '(' )			
			{
				++ i ;
				++ num ;
				flag = true ;
			}
			else
			{
				if( c1 == '-' )
				{
					cin >> c1 ;
					while( c1 >= '0' && c1 <= '9' )
					{				
						path[i] =  path[i] * 10  + ( c1 - '0' );
			    		cin >> c1 ;
					}
					path[i] = - path[i] ;
				}
				else
				{	
					while( c1 >= '0' && c1 <= '9' )
					{				
						path[i] = path[i] * 10 + c1 - '0' ;
			    		cin >> c1 ;
					}
				}
				num = 0 ;
				sum1 += path[i] ;				
				if( c1 == '(' )			
				{
					++ i ;
					++ num ;
					flag = true ;
				}
			}
		}		
	}
	return 0 ;
}