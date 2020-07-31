//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char lake[100];
int  count, length, ansi, ansd, n, counti, lengthi;


void solve(int i, int d){
	int ii;
	count = 1;
	length = 0;

	for (ii = i; ii < n - 1;)
	{
		if ('.' != lake[ii])	break;
		ii += d;
		count ++;
	}
	if (ii != n - 1)	return;
	length = ii;
	//printf("[%d %d %d %d]\n", i, d, count, length);
	if (count > counti)
	{
		ansi = i;
		ansd = d;
		counti = count;
		lengthi = length;
	}
	else if (count == counti && length > lengthi)
	{
		ansi = i;
		ansd = d;
		lengthi = length;
	}
	else if (count == counti && length == lengthi)
	{
		if (i > ansi)
		{
			ansi = i;
			ansd = d;
		}
		else if (i == ansi && d < ansd)
		{
			ansd = d;
		}
	}
}

int main(){
	while (EOF != scanf("%s", lake))
	{
		if (0 == strcmp(lake, "END"))	break;

		n = strlen(lake);
		ansi = ansd = counti = lengthi = 0;
		for (int i = 0; i < n ; i ++)
		{
			//if ('.' != lake[i])	continue;
			for (int d = 1; d < n; d ++)
			{
				solve(i, d);
			}
		}
		printf("%d %d\n", ansi, ansd);
		memset(lake, 0, sizeof(lake));
	}
	return 0;
}