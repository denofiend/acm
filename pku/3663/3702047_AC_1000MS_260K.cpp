//

#include <iostream>
#include <algorithm>
#define MAXN 20001
using namespace std;

int length[MAXN];

int main(){
	int n, k;
	while (EOF != scanf("%d %d", &n, &k))
	{
		int i, j;
		for (i = 0; i < n; i++)	scanf("%d", &length[i]);
		sort(length, length + n);
		int ans = 0;
		for (i = 0; i < n - 1; i ++)
		{
			for (j = i + 1; j < n; j ++)
			{
				if (length[i] + length[j] <= k)
					ans ++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}