//用数组下标 i 控制 树的层次变化在回朔的过程中要注意将该层的结点中数据更改为 0 
//这到题中学会了控制数组的下标（和数的层次联系起来） 
//还有关于不同集合之间的区别（很细小的区别很重要）

#include <iostream>
using namespace std ;
int main(){
	int sum , num = 0 , path[100] , i = 0 , sum1 = 0 , num1 = 0 ;
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
					num = 0 ;
				}
				//回朔时更改path[i + 1]	
				sum1 -= path[i + 1] ;
				path[ i + 1 ] = 0 ;
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
				}
			}
		}		
	}
	return 0 ;
}