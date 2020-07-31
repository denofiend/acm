// 1035(pku)


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10001
#define MAXL 20


char str[MAXN][MAXL];
int dicnum;

void print(char *check){
	int len = strlen(check);
	int i, j, k;
	// the string waiting checked in the dictionary
	for (i = 0; i < dicnum; i ++)
	{
		if (0 == strcmp(check, str[i]))
		{
			printf("%s is correct\n", check);
			return;
		}
	}
	// find all string meet one of the three conditions
	printf("%s:", check);
	for (i = 0; i < dicnum; i ++)
	{
		int len1 = strlen(str[i]), num = 0;

		if (1 < len - len1 || 1 < len1 - len )
			continue;
		if (len == len1)
		{
			for (j = 0; j < len; j ++)
				if (check[j] != str[i][j])
					num ++;
			if (1 >= num)
				printf(" %s", str[i]);
		}
		else if (len + 1 == len1)
		{
			for (j = 0, k = 0; j < len;)
			{
				for (; k < len1; k ++)
					if (check[j] == str[i][k])
					{
						k++;
						j++;
						break;
					}
				if (k == len1)
					break;
			}
			if (j == len)
				printf(" %s", str[i]);
		}
		else if (len == len1 + 1)
		{
			for (k = 0, j = 0; k < len1;)
			{
				for(; j < len; j ++)
				{
					if (str[i][k] == check[j])
					{
						j ++;
						k ++;
						break;
					}
				}
				if (j == len)
					break;
			}
			if (k == len1)
				printf(" %s", str[i]);
		}
	}
	printf("\n");
}
int main(){
	char input[MAXL], check[MAXL], *found;
	dicnum = 0;
	while (1 == scanf("%s", input))
	{
		if ('#' == input[0])
			break;
		strcpy(str[dicnum], input);
		dicnum ++;
	}

	while (1 == scanf("%s", check))
	{
		if ('#' == check[0])
			break;
		print(check);
	}
	return 0;
}

