//
#include <iostream>
#include <algorithm>
#include <math.h>
#define MAXN 2001
#define Inf 0xffffff
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i++)	out(x[i], m);	cout << endl;	}

int f[2][MAXN];
int elevation[MAXN], a[MAXN];
int ans, n;

void DP(){
	int i, j, curr = 0;
	sort(elevation, elevation + n);
	for (i = 0; i < n; i ++)	f[0][i] = (a[0] <= elevation[i]) ? 0 : (a[0] - elevation[i]);

	for (i = 1; i < n; i ++)
	{	
		curr = 1 - curr;
		f[curr][0] =f[1 - curr][0] + abs(a[i] - elevation[0]);	
		
		for (j = 1; j < n; j ++)
		{
			f[curr][j] = min(f[curr][j - 1], f[1 - curr][j] + abs(a[i] - elevation[j]));
		}
	}

	//ut(f, 2, n);
	//ans = f[n - 1][0];
	for (j = 0; j < n; j ++)
		if (ans > f[curr][j])	ans = f[curr][j];
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