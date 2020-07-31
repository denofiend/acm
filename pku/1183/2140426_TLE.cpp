 #include <stdio.h>
 int main()
 {
	_int64 a,i;
	scanf("%d",&a);
 	for(i = a; ;i --)
		if((a * a + 1) % i == 0)break;
	printf("%d\n",2 * a+(a * a + 1 )/ i + i);
	return 0;
 }
