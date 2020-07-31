#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory>

struct Node
{
	int v;
	Node *next;
};

struct point
{
	int st, ed;
};

const int N = 1 << 12;
Node *adj[N], *rev[N];
Node *newG[N], *newR[N];
Node table[N<<12];
int deg[N];
int sc[N], post[N];
int forbid[N];
bool vst[N];
int mark[N]; // 1 means selected, 0 means not selected, -1 means deleted
int stack[N], top;
int sorted[N], sn;
int index, cnt;
point pt[N];

inline void Join( int x, int y, Node *d[] )
{
	Node *p = &table[index++];
	p->v = y; p->next = d[x]; d[x] = p;
}

void dfs1( int v )
{
	vst[v] = 1;

	for ( Node *p = rev[v]; p != NULL; p = p->next )
	{
		if( !vst[p->v] ) dfs1( p->v );
	}

	post[cnt++] = v;
}

void dfs2( int v )
{
	sc[v] = cnt; vst[v] = 1;

	for ( Node *p = adj[v]; p != NULL; p = p->next )
	{
		if( !vst[p->v] ) dfs2( p->v );
	}
}

void SCC( int n )
{
	cnt = 0; memset( vst, 0, n );
	memset( sc, -1, sizeof( int ) * n );
	memset( post, -1, sizeof( int ) * n );

	for ( int i = 0; i < n; i++ )
	{
		if ( !vst[i] ) dfs1( i );
	}

	cnt = 0; memset( vst, 0, n );

	for ( int i = n - 1; i >= 0; i-- )
	{
		if ( !vst[post[i]] )
		{
			dfs2( post[i] ); cnt++;
		}
	}
}

void compression( int n )//缩点， 建新图
{
	for ( int i = 0; i < n; i++ )
	{
		for ( Node *p = adj[i]; p; p = p->next )
		{
			if ( sc[i] != sc[p->v] )
			{
				Join( sc[i], sc[p->v], newG );
				Join( sc[p->v], sc[i], newR );
				deg[sc[p->v]]++;
			}
		}
	}
}

//SCC结束后， cnt即为强连通分支的个数
void toposort( int n )
{
	top = 0; sn = 0;
	for ( int i = 0; i < cnt; i++ )
	{
		if ( deg[i] == 0 ) stack[top++] = i;
	}

	while ( top > 0 )
	{
		int t = stack[--top];
		sorted[sn++] = t;
		for ( Node *p = newG[t]; p; p = p->next )
		{
			deg[p->v]--;
			if ( deg[p->v] == 0 ) stack[top++] = p->v;
		}
	}
}

void solve( int n )
{
	SCC( n );
	for ( int i = 0; i < n; i += 2 )
	{
		if ( sc[i] == sc[i^1] )
		{
			puts( "NO" );
			return ;
		}
	}
	puts( "YES" );
	//新图的互斥关系
	for ( int i = 0; i < n; i += 2 )
	{
		forbid[sc[i]] = sc[i^1];
		forbid[sc[i^1]] = sc[i];
	}

	compression( n ); toposort( n );
	for ( int i = sn-1; i >= 0; i-- )
	{
		int v = sorted[i];
		if ( mark[v] == 0 )
		{
			mark[v] = 1;
			int w = forbid[v];
			mark[w] = -1;
			for ( Node *p = newR[w]; p; p = p->next )
			{
				mark[p->v] = -1;
			}
		}
	}

	for ( int i = 0; i < n; i += 2 )
	{
		if ( mark[sc[i]] == 1 )
		{
			printf( "%.2d:%.2d %.2d:%.2d\n", pt[i].st / 60, pt[i].st % 60, pt[i].ed / 60, pt[i].ed % 60 );
		}
		else
		{
			printf( "%.2d:%.2d %.2d:%.2d\n", pt[i^1].st / 60, pt[i^1].st % 60, pt[i^1].ed / 60, pt[i^1].ed % 60 );
		}
	}
	putchar( '\n' );
}

bool crash( int x, int y )
{
	if ( pt[x].ed > pt[y].st && pt[y].ed > pt[x].st ) return 1;
	return 0;
}

int main()
{
	int n;
	scanf( "%d", &n ); index = 0;
	for ( int i = 0; i < n; i++ )
	{
		int x, d;
		int start, end;
		char s1[15], s2[15];
		scanf( "%s%s%d", s1, s2, &d );
		start = ( s1[0] - '0' ) * 10 + s1[1] - '0';
		start *= 60; start += ( s1[3] - '0' ) * 10 + s1[4] - '0';

		end = ( s2[0] - '0' ) * 10 + s2[1] - '0';
		end *= 60; end += ( s2[3] - '0' ) * 10 + s2[4] - '0';
		x = ( i << 1 );
		pt[x].st = start; pt[x].ed = start + d;
		pt[x^1].st = end - d; pt[x^1].ed = end;
	}

	n <<= 1;
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			if ( j == ( i^1 ) ) continue;
			if ( crash( i, j ) || crash( j, i ) )
			{
				Join( i, j^1, adj ); Join( j, i^1, adj );
				Join( j^1, i, rev ); Join( i^1, j, rev );
			}
		}
	}
	solve( n );

    return 0;
}

