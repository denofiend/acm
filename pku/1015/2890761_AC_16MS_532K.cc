// 1015(pku)
// DP

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// f[j,k]表示：取j个候选人，使其控辩差为k的所有方案中
// 控辩和最大的那个方案（该方案称为“方案f[j,k]")的
// 控辩和
int f[30][1000];
// path[j, k]记录选取了f[j,k]选取的人的编号
int path[30][1000];
int p[300], d[300], ans[300];

int Com( const void *a, const void * b ){
	return ( *(int *)a ) - ( * ( int * )b );
}

int main(){
	int i, j, k, t1, t2, n, m, nMinP_D, nCaseNo = 0;
	//freopen("a.in", "r", stdin);
	while ( 2 == scanf("%d %d\n", &n, &m) )
	{
		if ( 0 == n && 0 == m )
			break;
		nCaseNo ++;
		for ( i = 1; i <= n; ++ i )
			scanf("%d %d", &p[i], &d[i]);
		memset( f, -1, sizeof(f) );
		memset( path, 0, sizeof(path) );
		nMinP_D = m * 20;
		f[0][nMinP_D] = 0;
		for ( j = 0; j < m; ++ j )
		{
			for ( k = 0; k <= nMinP_D * 2; ++ k )
			{
				if ( f[j][k] >= 0 )
				{
					for ( i = 1; i <= n; ++ i )
					{
						if ( f[j][k] + p[i] + d[i] >
							 f[j + 1][k + p[i] - d[i]] ) 
						{
							t1 = j, t2 = k;
							while ( t1 > 0 && path[t1][t2] != i )
							{
								t2 -= p[ path[t1][t2] ] -
									 d[ path[t1][t2] ];
								t1 --;
							}
							if ( 0 == t1 )
							{
								f[j + 1][k + p[i] - d[i]] =
									 f[j][k] + p[i] + d[i];
								path[j + 1][k + p[i] - d[i]] = i;
							}
							
						}
					}
				}
			}
		}
		i = nMinP_D;
		j = 0;
		while ( f[m][i + j] < 0 && f[m][i - j] < 0 )
 			j ++;
		if ( f[m][i + j]  > f[m][i - j ] )
			k = i + j;
		else
			k = i - j;
		printf("Jury #%d\n", nCaseNo);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",
			(k - nMinP_D + f[m][k] ) / 2, (f[m][k] - k + nMinP_D) / 2);
		for ( i = 1; i <= m; ++i )
		{
			ans[i] = path[m - i + 1][k];
			k -= p[ ans[i] ] - d[ ans[i] ];
		}
		qsort( ans + 1, m, sizeof(int), Com );
		for ( i = 1; i <= m; ++ i )
			printf(" %d", ans[i]);
		printf("\n\n");		
	}
	
	return 0;
}

