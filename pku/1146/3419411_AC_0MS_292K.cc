#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[100], ls;

int main()
{
	while (scanf("%s", s) != -1 && strcmp(s, "#"))
	{
		ls = strlen(s);
		if (next_permutation(s, s + ls))
		{
			printf("%s\n", s);
		}
		else
		{
			printf("No Successor\n");
		}
	}
	return 0;
}
