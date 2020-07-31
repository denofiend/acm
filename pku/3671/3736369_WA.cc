//
#define __STDC_LIMIT_MACROS
#include <iostream>
#define MAXN 30010
using namespace std;


int a[MAXN], n;
int f[MAXN];

int cal(int pos){
	//printf("pos = %d\n", pos);
	int ret1 = 0, ret2 = 0;
	ret1 = f[pos - 1] < (pos - f[pos - 1]) ? f[pos - 1] : (pos - f[pos - 1]);
	ret2 = (f[n - 1] - f[pos - 1]) < (n - pos - f[n - 1] + f[pos - 1]) ?  (f[n - 1] - f[pos - 1]) : (n - pos - f[n - 1] + f[pos - 1]);
	return ret1 + ret2;
}

void init(){
	int i;
	if (1 == a[0])	f[0] = 1;
	else f[0] = 0;
	for (i = 1; i < n; i ++)
	{
		if (1 == a[i])	f[i] = f[i - 1] + 1;
		else f[i] = f[i - 1];
	}
}

int main(){
	while (EOF != scanf("%d", &n))
	{
		int i;
		for (i = 0; i < n; i ++)	scanf("%d", &a[i]);
		init();
		int ans = INT32_MAX;

		for (i = 1; i < n - 1; i ++)
		{
			int cnt =  cal(i);
			if (ans > cnt)	ans = cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}