// 1258(pku)

#include <iostream>
#include <algorithm>

using namespace std;
#define EMAX 10001

struct Edge{
	int sta, end, val;
};

Edge edge[EMAX] ;
int father[101], rank[101], town[101][101], n, en;

bool cmp( const Edge & a, const Edge & b ){
	return a.val < b.val ;
}
int findset( const int x ){
	if ( x != father[x] )
		father[x] = findset( father[x] );
	return father[x];
}
int kruskal(){
	int i, v, u, mst = 0;
	for ( i = 1; i <= n; i ++ )
		father[i] = i;
	sort( edge + 1, edge + en, cmp ) ;

	for ( i = 1; i < en; i ++ )
	{
		u = findset( edge[i].sta );
		v = findset( edge[i].end );
		if( u != v )
		{
			father[u] = v;
			mst += edge[i].val ;
		}
	}
	return mst ;
}
int main(){
	int i, j;
	while ( cin >> n )
	{
		for ( i = 1, en = 1; i <= n; i ++ )
			for ( j = 1; j <= n; j ++ )
			{
				cin >> town[i][j] ;
				town[j][i] = town[i][j] ;
			}
		en = 1;
		for ( i = 1; i <= n; i ++ )
			for ( j = 1; j <= n; j ++ )
			{
				if( i != j )
				{
					edge[en].sta = i;
					edge[en].end = j;
					edge[en++].val = town[i][j];
				}
			}

		cout << kruskal() << endl ;
	}
	return 0 ;
}
