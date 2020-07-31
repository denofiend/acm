#include <stdio.h>

#define Z_SIZ 10024
#define R_SIZ 50
int Z[Z_SIZ];

int jeste;
void init()
{
	int i;
	jeste= R_SIZ;
	for(i= Z_SIZ; i--;)
	{
		Z[i]= -1;
	}
}

void pr(char c)
{
	if (jeste == 0 )
	{
		jeste= R_SIZ;
		printf("\n");
	}
	jeste --;
	printf("%c", c);
}
void tisk(int num, int den)
{
	int zb;
	int digit;
	init();
	pr('.');
	digit=0;
	while(1)
	{
		num*= 10;
		zb= num % den;

#ifdef DB
		printf("num:%i\n", num);
#endif

		if( zb == 0)
		{
			pr('0' + num/den);
			printf("\nThis expansion terminates.\n");
			return;
		}
		if( Z[num] != -1 )
		{
			printf("\nThe last %i digits repeat forever.\n", digit - Z[num]);
			return;
		}
		pr('0' + num/den);
		Z[num]= digit;
		num -= den * ( num / den);	
		digit++;
	}
}	

int main()
{
	int A, B;
	while(1)
	{
		scanf("%d %d", &A, &B);
		if( A == 0 )
		{
			return 0;
		}
		tisk (A, B);
	}
}
