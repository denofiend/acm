#include <stdio.h>

#include <string.h>

long b2ten( char *x, int b ){
	int ret = 0;
	int len = strlen(x);
	for ( int i = 0; i < len; i ++ )
	{
		if ( x[i] - '0' >= b ) return -1;
		ret *= b;
		ret += x[i] - '0';
	}
	return (long)ret;
}

int main(){
	int n, b;
	char p[8], q[8], r[8];
	long pAlgorithm, qAlgorithm, rAlgorithm;
	scanf("%d", &n);
	while ( n -- )
	{
		scanf("%s %s %s", p,q, r);
		for ( b = 2; b <= 16; b ++ )
		{
			pAlgorithm = b2ten(p, b);
			qAlgorithm = b2ten(q, b);
			rAlgorithm = b2ten(r, b);
			if ( -1 == pAlgorithm && -1 == qAlgorithm && - 1 == rAlgorithm )
				continue;
			if ( pAlgorithm * qAlgorithm == rAlgorithm )
			{
				printf("%d\n", b);
				break;
			}
		}
		if ( 17 == b )
			printf("0\n");
	}
	return 0;
}