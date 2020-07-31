//
#define __STDC_LIMIT_MACROS
#include <iostream>
#define MAXN 30001
using namespace std;


int a[MAXN], n;


int cal(int pos){
	int i, ret = 0, ret1 = 0;
	for (i = 0; i < pos; i ++)
	{
		if (1 == a[i])	ret ++;
	}
	ret = ret < (pos - ret) ? ret : (pos - ret);

	for (i = pos; i < n; i ++)
	{
		if (1 == a[i])	ret1 ++;
	}
	ret1 = ret1 <(n - pos - ret1) ? ret1 : (n - pos - ret1);
	return ret + ret1;
}

int main(){
	while (EOF != scanf("%d", &n))
	{
		int i;
		for (i = 0; i < n; i ++)	scanf("%d", &a[i]);

		int ans = INT32_MAX;

		for (i = 1; i < n - 1; i ++)
		{
			int cnt = cal(i);
			if (ans > cnt)	ans = cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}