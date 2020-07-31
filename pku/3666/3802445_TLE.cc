//

#include <iostream>
#include <algorithm>
#define MAXN 2001
#define Inf 0xffffff
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i++)	out(x[i], m);	cout << endl;	}

int f[MAXN][MAXN];
int elevation[MAXN], a[MAXN];

bool cmp(const int &a, const int &b){
	return a > b;
}

int main(){
	int n, i, j, k, pos;
	while (EOF != scanf("%d", &n))
	{
		for (i = 0; i < n; i ++)
		{
			scanf("%d", &elevation[i]);
			a[i] = elevation[i];
		}
		
		sort(elevation, elevation + n, cmp);
		
		//out(elevation, n);
		//cout << endl;
		//out(a, n);
		//cout << endl;	
		for (i = 0; i < n; i ++)	f[0][i] = abs(a[0] - elevation[n - 1 - i]);

		for (i = 1; i < n; i ++)
		{			
			for (j = 0; j < n; j ++)
			{
				f[i][j] =f[i - 1][0];
				pos = i;
				for (k = 0; k <= j; k ++)
				{
					if (f[i - 1][k] <= f[i][j])
					{
						pos = k;
						f[i][j] = f[i - 1][k];
					}
				}
				//printf("[%d %d %d %d]\n", j, pos, elevation[i], elevation[pos]);
				f[i][j] += abs(a[i] - elevation[n - 1 - j]);
			}
		}
		//out(f, n, n);
		int ans = f[n - 1][0];
		for (j = 1; j < n; j ++)
			if (ans > f[n - 1][j])	ans = f[n - 1][j];
		printf("%d\n", ans);
		
	}
	return 0;
}