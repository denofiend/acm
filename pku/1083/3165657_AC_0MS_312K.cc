


#include <stdio.h>

int main()
{
	int cas,n,i,up,down,temp;
	int a[200];
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (i=0; i<200; i++)  a[i] = 0;
		while (n--)
		{
			scanf("%d %d",&down,&up);
			if (down > up)
			{
				temp = down;
				down = up;
				up = temp;
			}
			down = (down - 1) / 2;
			up = (up - 1) / 2;
            //printf("down = %d, up = %d\n", down, up);
			for (i=down; i<=up; i++)
				a[i]++;
		}
		int max = 0;
		for (i=0; i<200; i++)
			if (a[i] > max)  max = a[i];
		printf("%d\n",max * 10);
	}
	return 0;
}
