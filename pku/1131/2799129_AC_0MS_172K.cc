// 1131

#include <stdio.h>
#include <math.h>
#include <string.h>
char s[50];
int ans[200], target[200];
int main(){
	int i, j, size, nsize, num, k, tmp;
	const int div = 8;
	while ( 1 == scanf("%2*c%s\n", s) )
	{
		size = strlen( s );
		nsize = 3 * size ;
		
		memset( target, 0, sizeof( target ) );
		for ( i = 0, j = 0; i < size; ++ i )
		{
			memset( ans, 0, sizeof( ans ) );
			for ( k = 0, num = s[i] - '0'; k <= i; k ++, num = 0 )
			{
				for ( j = 0; j <= nsize + 1; ++ j )
				{			
					if( 0 == k )
					{
						num *= 10;
						ans[j] = num / div;
						num %= div;
					}
					else
					{
						num *= 10;
						tmp = (ans[j] + num) % div;
						ans[j] = (ans[j] + num) / div;
						num = tmp;

					}
				}
			}
			j = nsize , num = 0;
			while ( j >= 0 )
			{
				target[j] += ans[j] + num;
				num = target[j] / 10;
				target[j] %= 10;
				j -- ;
			}
		}
		printf("0.%s [8] = 0.", s);
		for ( i = 0; i < nsize - 1; i ++ )
			printf("%d", target[i]);
		if ( target[nsize] >= 5 || target[nsize] == 4 && target[nsize + 1] >= 5 )
			printf("%d", target[nsize - 1] + 1);
		else
			printf("%d", target[nsize - 1]);
		printf(" [10]\n");

	}
	return 0;
}
