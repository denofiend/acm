#include <stdio.h>

int check(int n, int x)
{
	int i;
	for (i = 0; i < x; i++)
	{
		if ((n - 1) % x == 0)
		{
			n = n - 1 - n / x;
		}
		else
		{
			return 0;
		}
	}
	if (n % x != 0)
	{
		return 0;
	}
	return 1;
}

void Calc(int n)
{
	int i;
	for (i = n; i > 1; i--)
	{
		if (check(n, i))
		{
			printf("%d coconuts, %d people and 1 monkey\n", n, i);
			return;
		}
	}
	printf("%d coconuts, no solution\n", n);
}

int main()
{
	int n;
	while (scanf("%d", &n) != -1 && n != -1)
	{
		Calc(n);
	}
	return 0;
}
