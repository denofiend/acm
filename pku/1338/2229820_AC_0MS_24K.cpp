#include <stdio.h>
#define maxn 1500

int min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int i,n;
	int a,b,c,pa,pb,pc;
	int num[maxn+5]={0};
	num[1]=pa=pb=pc=1;
	for (i=2;i<=maxn;i++)
	{
		a=num[pa]*2;b=num[pb]*3;c=num[pc]*5;
		num[i]=min(min(a,b),c);
		if (a==num[i]) pa++;
		if (b==num[i]) pb++;
		if (c==num[i]) pc++;
	}
	
	scanf("%d",&n);
	while (n!=0)
	{
		printf("%d\n",num[n]);
		scanf("%d",&n);
	}
	return 0;
}
