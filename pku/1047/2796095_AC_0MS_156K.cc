// 1047(pku)
// 看什么是循环数

#include <stdio.h>
#include <string.h>

int main(){
	char c[61];
	int i, j, k, flag[10], num, csize, flag1 ;
	while ( gets(c) )
	{
		flag1 = 0;
		csize = strlen( c );
		for ( k = 1; k <= csize; ++ k )
		{
			memset( flag, 0, sizeof( flag ) );
			for ( i = 0; i < csize; ++ i )
				flag[ c[i] - '0' ] ++ ;
			i = csize - 1, j = 0;
			while ( i >= 0 )
			{
				num = ( c[i] - '0') * k + j;
				j = num / 10;
				num %= 10;
				flag[ num ] -- ;
				i -- ;
			}
			if ( j )
				flag1 = 1;
			for ( i = 0; i < csize && !flag1; ++ i )
				if( flag[ c[i] - '0' ] )
				{
					flag1 = 1;
					break;
				}
			if ( flag1 )
				break ;
		}
		printf("%s ", c);
		if ( flag1 )
			printf("is not cyclic\n");
		else
			printf("is cyclic\n");
	}
	return 0;
}
