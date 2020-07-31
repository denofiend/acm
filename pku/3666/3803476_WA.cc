//
#include <iostream>
#include <algorithm>
#include <math.h>
#define MAXN 2001
#define Inf 0xffffff
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i++)	out(x[i], m);	cout << endl;	}

int f[MAXN][MAXN];
int elevation[MAXN], a[MAXN];
int ans, n;

void DP(){
	int i, j;
	for (i = 0; i < n; i ++)	f[0][i] = (a[0] <= elevation[i]) ? 0 : (a[0] - elevation[i]);

	for (i = 1; i < n; i ++)
	{	
		f[i][0] =f[i - 1][0] + abs(a[i] - elevation[0]);	
		
		for (j = 1; j < n; j ++)
		{
			f[i][j] = min(f[i][j - 1], f[i - 1][j] + abs(a[i] - elevation[j]));
		}
	}

	//out(f, n, n);
	//ans = f[n - 1][0];
	for (j = 0; j < n; j ++)
		if (ans > f[n - 1][j])	ans = f[n - 1][j];
}

int main(){
	while (EOF != scanf("%d", &n))
	{
		ans = Inf;
		for (int i = 0; i < n; i ++)
		{
			scanf("%d", &elevation[i]);
			a[i] = elevation[i];
		}
		
		sort(elevation, elevation + n);
		DP();
		for (int i = 0; i < n; i ++)
		{
			a[i] *= -1;
			elevation[i] *= -1;
		}
		DP();
		printf("%d\n", ans);
	}
	return 0;
}