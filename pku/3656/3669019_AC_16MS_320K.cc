// WA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char lake[100];
int  count, length, n;

struct Node{
	int i, d, count, length;
};
Node nd[10000];
int cnt;
int cmp(const void *a, const void *b){
	Node *aa = (Node *)a;
	Node *bb = (Node *)b;

	if (aa->count > bb->count)	return 1;
	else if (aa->count == bb->count && aa->length > bb->length)	return 1;
	else if (aa->count == bb->count && aa->length == bb->length)
	{
		if (aa->i > bb->i)	return 1;
		else if (aa->i == bb->i && aa->d < bb->d)	return 1;
		else return -1;
	}
	else return -1;
}
void solve(int i, int d){
	int ii;
	count = 0;

	for (ii = i; ii < n - 1;)
	{		
		if ('.' != lake[ii])	break;
		ii += d;
		count ++;		
	}
	if (ii > n - 1)	ii = n - 1;
	length = ii;
	if (ii !=i)	count++;
	nd[cnt].i = i;
	nd[cnt].d = d;
	nd[cnt].length = length;
	nd[cnt++].count = count;
}

int main(){
	while (EOF != scanf("%s", lake))
	{
		if (0 == strcmp(lake, "END"))	break;

		n = strlen(lake);
		cnt = 0;
		for (int i = 0; i < n ; i ++)
		{
			for (int d = 1; d < n; d ++)
			{
				solve(i, d);
			}
		}
		qsort(nd, cnt, sizeof(nd[0]), cmp);
		printf("%d %d\n", nd[cnt - 1].i, nd[cnt - 1].d);
	}
	return 0;
}