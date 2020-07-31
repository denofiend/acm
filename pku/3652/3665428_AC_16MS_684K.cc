//
#define __STDC_LIMIT_MARCROS
#include <iostream>
#define MAXN 65550
using namespace std;

int table[MAXN];
bool st[MAXN];
char ans[20];

int main(){
	int a, b, c, s, i, j, k, x1, s0, base;
	char flag;
	while (EOF != scanf("%d", &a))
	{
		if (0 == a)	break;
		scanf("%d %d %d", &b, &c, &s);
		//printf("%d %d %d %d\n", a, b ,c, s);
		i = j = 0;
		table[j++] = s;
		memset(st, 0, sizeof(st));
		st[s] = true;
		s0 = s;

		for (;;)
		{
			x1 = (a * s0 + b) % c;
			//printf("x1 = %d\n", x1);
			if (st[x1])	break;
			st[x1] = true;
			table[j++] = x1;
			s0 = x1;
		}
		memset(ans, 0, sizeof(ans));
		ans[16] = '\0';
		for (base = 1, i = 15; base < MAXN; base <<= 1, i --)
		{
			if (base & table[0])
			{
				flag = '1';
			}
			else 
			{
				flag = '0';
			}
			
			for (k = 1; k < j; k ++)
			{
				if ((base & table[k] && '0' == flag) || (0 == (base & table[k]) && '1' == flag))
				{
					flag = '?';
					break;
				}
			}
			ans[i] = flag;
		}
		printf("%s\n", ans);
	}
	return 0;
}