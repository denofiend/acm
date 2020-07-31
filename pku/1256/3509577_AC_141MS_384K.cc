#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

bool mycompare(char a, char b)
{
	char c,d;
	c=tolower(a);
	d=tolower(b);

	if(c==d)
		return (a<b);

	return c<d;
}

int main()
{
    //freopen("a.in", "r", stdin);
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	char s[16];
	scanf("%s",s);
	int len=strlen(s);
	sort(s,s+len,mycompare);
	int j;
	do{
		for(j=0;j<len;j++)
		{
			printf("%c",s[j]);
		}
		printf("\n");
	}while(next_permutation(s,s+len, mycompare));

	}
    return 0;
}
