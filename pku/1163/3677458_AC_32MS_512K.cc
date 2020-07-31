//

#include <iostream>
#define MAXN 110
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}

int f[MAXN][MAXN];
int elem[MAXN][MAXN];

int main(){
	int n;
	while (cin >> n)
	{
		int i, j;
		for (i = 0; i < n; i ++)
		{
			for (j = 0; j <= i; j ++)
			{
				cin >> elem[i][j];
			}
		}

		memset(f, 0, sizeof(f));

		f[0][0] = elem[0][0];
		for (i = 1; i < n ;i ++)
		{
			f[i][0] = f[i - 1][0] + elem[i][0];
			for (j = 1; j <= i; j ++)
			{
				f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + elem[i][j];
			}
		}
		int ans = f[n - 1][0];
		for (i = 1; i < n;  i++)
		{
			if (ans < f[n - 1][i])	ans = f[n - 1][i];
		}
		cout << ans << endl;
	}
	return 0;
}