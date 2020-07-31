// 1126 pku
// 正则表达式
// 正确理解匹配
#include <iostream>
#include <string>
using namespace std ;
int main(){
	string c ;
	while( cin >> c )
	{
		int num = 1 ;
		for( int i = 0; i < c.size() ; i ++ )
		{
			if( 'C' == c[i] || 'D' == c[i] || 'E' == c[i] || 'I' == c[i] )
				num ++ ;
			else if( 'p' <= c[i] && 'z' >= c[i] )
				num -- ;
			else if( 'N' != c[i] )
			{
				num = 1 ;
				break ;
			}
		}
		if( 0 == num )
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;
	}
	return 0 ;
}