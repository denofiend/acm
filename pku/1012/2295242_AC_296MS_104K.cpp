//============
//
// 打表算法
//
//---------
#include <iostream>
using namespace std ;
bool test(int m, int N)
{
	int i, p;
	m -- , i = 0 ;	
	for( p = 2 * N; p > N; p -- )            //p代表当前状态的总人数
	{
		i = (i + m) % p;                     //计算i 进行选择后在圈中所处的位置
		if(i < N)                            //i位于good guys 中的一个
			return false ;                         
	}
	return true ;
}

int main()
{
	int m, N , a[14] ;
	for( N = 1; N < 14; N ++ )
	{	
		for(m = N + 1 ; ; m++)
		{
			if( test(m, N))
			{
				a[N] = m ;
				break;
			}
		}
		
	}
	int n ;
	while( cin >> n  && n != 0 )
		cout << a[n] << endl ;
	return 0 ;
}