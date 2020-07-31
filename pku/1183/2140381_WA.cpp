#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 60000
int main(){
	int a , b , c , min ;
	scanf("%d",&a);
	b = 2 * a - 1;
	c = 2 * a + 2;
	min = b + c;
	for(int i = b;i >= 1;i --){
		for(int j = c;j <= MAXSIZE; j ++)
		{
			if( (i + j) < min)
				min = i + j;
		}
	}
	printf("%d",min);
	return 0;
}