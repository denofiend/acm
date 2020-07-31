//

#include <iostream>
#define MAXN 100000
using namespace std;


bool flag[MAXN];
int n, m;

int main(){
	int case1 = 0, m, n, a, b, i, ans;
	while (EOF != scanf("%d %d", &n, &m))
	{
		if (0 == n && 0 == m)	break;
		memset(flag, false, sizeof(bool) * (n * m));

		for (i = 0; i < m; i ++)
		{
			scanf("%d", &a);
			flag[a - 1] = true;
		}

		a = b = ans = 0;
		for (i = n * m - 1; i >= 0;)
		{
			for (; i >= 0 && !flag[i]; i --)	a++;

			for (; i >= 0 && flag[i]; i --)	b++;

			if (b >= a)
			{
				ans += (b - a);
				a = b = 0;
			}
		}
		++case1;
		printf("Case %d: %d\n", case1, ans);
	}
	return 0;
}