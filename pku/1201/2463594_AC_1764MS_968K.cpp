// 1201 
// 差分约束
//  利用了BELLMAN_FORD()算法
//  最短路径的三角不等式

#include <iostream>
using namespace std ;
#define MAXE 60000
struct Edge{
	int sta, end, val ;
} ;
Edge edge[MAXE] ;
int dist[MAXE], min1, max1, n ;
int BellmanFord(){
	int i, j ;
	bool flag ;
	for( i = min1; i <= max1; i ++ )
		dist[i] = - MAXE;
	dist[min1] = 0 ;
	for( i = 0; i <= max1 - min1 ; i ++ )
	{
		flag = true ;
		for( j = 0; j < n; j ++ )
			if( dist[ edge[j].sta ] != - MAXE && dist[ edge[j].sta ] + edge[j].val > dist[ edge[j].end ] )
			{
				dist[ edge[j].end ] = dist[ edge[j].sta ] + edge[j].val ;
				flag = false ;
			}
		for( j = min1; j < max1 ; j ++ )
			if( dist[j] != - MAXE && dist[j] > dist[j + 1] )
			{
				dist[j + 1] = dist[j] ;
				flag = false ;
			}
		for( j = max1; j > min1; j -- )
			if( dist[j] != - MAXE && dist[j] - 1 > dist[j - 1] )
			{
				dist[j - 1] = dist[j] - 1 ;
				flag = false ;
			}
		if( flag )
			break ;
	}
	return dist[max1] ;
}
int main(){
	while( cin >> n )
	{
		max1 = 0, min1 = MAXE ;
		for( int i = 0; i < n; i ++ )
		{
			cin >> edge[i].sta >> edge[i].end >> edge[i].val ;
			edge[i].end ++ ;
			if( edge[i].sta < min1 )
				min1= edge[i].sta ;
			if( edge[i].end > max1 )
				max1 =edge[i].end ;
		}
		cout << BellmanFord() << endl ;
	}
	
	return 0 ;
}