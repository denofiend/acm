//

#include <iostream>
#include <ctype.h>
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i++)	out(x[i], m);	cout << endl;	}

int id(char c){
	int ret = 1 << (c - 'a' + 1);
	return ret;
}

char log[100];
char set[100];
int table[100];
int flag[30];
int ans[30];

void solve(int n){
	//printf("%s\n", set);
	//printf("n = %d\n", n);
	int k, i, j, elem;
	for (k = 0; k < n; k ++)
		if ('-' == set[k] || '=' == set[k] || '+' == set[k])
			break;
	if ('=' == set[k])
	{
		for (i = 0; i < k; i ++)
			table[ set[i] - 'A' ] = 0;
	}
	for (i = 0; i < k; i ++)
	{
		for (j = k + 1; j < n; j ++)
		{
			elem = id(set[j]);
			//printf("[%c %c %d]\n", set[i], set[j], elem);
			if ('-' == set[k] && table[ set[i] - 'A'] & elem)
			{
				table[ set[i] - 'A' ] ^= elem;
			}
			else if ('+' == set[k])
			{
				table[ set[i] - 'A' ] |= elem;
			}
			else if ('=' == set[k])
			{
				table[ set[i] - 'A' ] |= elem;
			}
		}
	}
}

void output(){
	memset(flag, 0, sizeof(flag));
	int i, j, k;
	bool same;
	for (i = 0; i < 26; i ++)
	{
		same = false;
		int id = table[i];
		if (0 == id || flag[i])	continue;
		flag[i] = 1;
		for (j = i + 1, k = 0; j < 26; j ++)
		{
			if (id != table[j] && table[j] > 0)	break;
			if (id == table[j] && !flag[j])
			{
				same = true;
				ans[k++] = j;
				flag[j] = 1;
			}
		}
		printf("%c", i + 'A');
		if (same)
		{			
			for (j = 0; j < k; j ++)
				printf("%c", ans[j] + 'A');
			for (int base = 1, j = 0; j <= 26; base <<= 1, j++)
			{
				if (base & id)
				{
					printf("%c", j + 'a' - 1);
				}
			}
		}
		else 
		{
			for (int base = 1, j = 0; j <= 26; base <<= 1, j++)
			{
				if (base & id)
				{
					printf("%c", j + 'a' - 1);
				}
			}			
		}
	}
	printf("\n");
}

int main(){
	int testcase = 1;
	
	while (EOF != scanf("%s", log))
	{
		if ('#' == log[0])	break;
		memset(table, 0, sizeof(table));

		int n = strlen(log);
		for (int i = 0, j = 0, k; i <= n; i ++)
		{
			if (',' == log[i] || i == n)
			{
				for (k = 0; j < i; j ++)
				{
					set[k++] = log[j];
				}
				set[k] = '\0';
				solve(k);				
				j = i + 1;
			}
		}
		//out(table, 26);
		printf("%d:", testcase++);
		output();
	}
	return 0;
}