// 1258(pku)

#include <iostream>
#include <algorithm>
#define EMAX 10001

using namespace std ;

struct Edge{
	int sta, end, val ;
};
Edge edge[EMAX];
int father[101], n, en;


bool cmp( const Edge & a, const Edge & b ){
	return a.val < b.val ;
}
int findset( const int x ){
	if( x != father[x] )
		father[x] = findset( father[x] );
	return father[x] ;
}
int kruskal(){
	int i, mst = 0, u, v;
	for ( i = 1; i <= n; i ++ )
		father[i] = i;
	sort( edge, edge + en, cmp );
	for ( i = 0; i < en; i ++ )
	{
		u = findset( edge[i].sta );
		v = findset( edge[i].end ) ;
		if( u != v )
		{
			father[u] = v;
			mst += edge[i].val ;
		}
	}
	return mst ;
}
int main(){
	int i, j, val;
	while ( 1 == scanf("%d", &n) )
	{
		en = 0; 
		for ( i = 1; i <= n; i ++ )
			for ( j = 1; j <= n; j ++ )
			{
				cin >> val ;
				if ( i != j )
				{
					edge[en].sta = i;
					edge[en].end = j;
					edge[en++].val = val ;
				}
			}
		printf("%d\n", kruskal()) ;
	}
	return 0 ;
}