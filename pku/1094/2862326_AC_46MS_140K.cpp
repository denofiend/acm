// 1094(pku)

#include <iostream>
#define VMAX 27
#define MAPPING 64

using namespace std;

int  less[VMAX][VMAX], vTp[VMAX], vInDo[VMAX], sort[VMAX][VMAX], vIn[VMAX], stack[VMAX], visited[VMAX];
/* the number of vertix and the number of edge */
int n, m;
/* use DFS to cheack if there exit a circle */
bool IsCircle(){
	int i, top, j;	
	for ( i = 1; i <= n; i ++ )
	{
		memset( visited, 0, sizeof( visited ) );
		top = 1;
		stack[top] = i;
		/* remember don't set the visited[i] = true */
		//visited[i] = true;
		while ( top )
		{
			int v = stack[top];
			for ( j = 1; j <= n; j ++ )
				if ( less[v][j] && !visited[j] )
				{
					visited[j] = true;
					stack[++top] = j;
					if ( i == j )
						return true;
					break;
				}
			if ( j == n + 1 )
				top --;
		}
	}
	return false;
}
/* check if there exit a circle
   if there exit return -1
   if there is a TopoSort seq return 1
   else return 0
*/
int checkDo(){
	int i, flag = 0, top, j = 0;
	/* copy the less[][] to sort[][] */
	for ( i = 1; i <= n; i ++ )
		for ( j = 1;j <= n; j ++ )
			sort[i][j] = less[i][j];
	/* copy the vInDo[] to vIn[] */
	for ( i = 1; i <= n; i ++ )
		vIn[i] = vInDo[i];

	for ( i = 1; i <= n; i ++ )
	{
		if ( 0 == vIn[i] )
		{
			flag ++;
			top = i;
		}
	}
	if ( 0 == flag )
		return - 1;
	else if ( IsCircle() )
		return - 1;
	else if ( 1 < flag )
		return 0;
	/* tmp used to record the top */
	int tmp;
	j = 0;
	/* TopoSort */
	while ( 1 == flag )
	{
		tmp = top;
		vTp[j ++] = tmp;
		flag = 0;
		for ( i = 1; i <= n; i ++ )
		{
			if ( top != i )
			{
				if ( sort[tmp][i] )
				{
					vIn[ sort[tmp][i] ] --;
					if ( 0 == vIn[sort[tmp][i]] )
					{
						top = sort[tmp][i];
						flag ++;
					}
				}
			}
		}
	}
	if ( j == n && 0 == flag )
		return 1;
	else if ( 0 == flag )
		return -1;
	else
		return 0;
}
int main(){
	while ( cin >> n >> m )
	{
		if ( 0 == n && 0 == m )
			break;
		memset( less, 0, sizeof( less ) );
		memset( vTp, 0, sizeof( vTp ) );
		memset( vInDo, 0, sizeof( vInDo ) );
		/* edge_index, sorted_pos, circle_pos */
		int e_ids, circle, spos = 0, cpos = 0, isCircle = false, sorted = false;
		/* two vertix from and to */
		char from, to;

		for ( e_ids = 1; e_ids <= m; e_ids ++ )
		{
			cin >> from >> to >> to;
			
			from -= MAPPING;
			to -= MAPPING;
			less[ from ][ to ] = to;
			vInDo[ to ] ++;

			circle = checkDo();
			if ( 1 == circle && !sorted )
			{
				spos = e_ids;
				sorted = true;
			}
			/* !sorted is imported */
			else if ( -1 == circle && !isCircle && !sorted )
			{
				cpos = e_ids;
				isCircle = true;
			}
		}
		if ( isCircle )
			cout << "Inconsistency found after " << cpos <<" relations." << endl;
		else
		{
			if ( sorted )
			{
				cout << "Sorted sequence determined after " << spos << " relations: ";
				for ( int i = 0; i < n; i ++ )
					cout << char(vTp[i] + MAPPING);
				cout << ".\n";
			}
			else
				cout << "Sorted sequence cannot be determined." << endl;
		}
	}
	return 0;
}