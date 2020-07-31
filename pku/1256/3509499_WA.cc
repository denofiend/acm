//


#include <iostream>
#include <algorithm>

using namespace std;

char str[20];

int comp(const void *c, const void *d)
{
	int valuea, valueb, sta, stb, a, b;
	a=*(char *)c;
	b=*(char *)d;
	if (a >= 'A' && a <= 'Z')
	{
		valuea = a - 'A';
		sta = 0;
	}
	else
	{
		valuea = a - 'a';
		sta = 1;
	}

	if (b >= 'A' && b <= 'Z')
	{
		valueb = b - 'A';
		stb = 0;
	}
	else
	{
		valueb = b - 'a';
		stb = 1;
	}

	if(valuea != valueb)
	{
		return valuea - valueb;
	}
	else
	{
		return sta - stb;
	}
}
int main(){
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n --)
    {
        memset(str, 0, sizeof(str));
        scanf("%s", str);

        int len  = strlen(str);
        qsort(str, len, sizeof(char), comp);

        printf("%s\n", str);
        while (next_permutation(str, str + len))
        {
            printf("%s\n", str);
        }
    }
    return 0;
}
