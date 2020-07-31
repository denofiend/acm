//

#include <iostream>
#define MAXN 1001
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i] << ' ';	cout << endl;	}

int rate[MAXN];

int main(){
	int n, m;
	while (EOF != scanf("%d %d", &n, &m))
	{
		int i, j;
		for (i = 1; i <= n; i ++)
			scanf("%d", &rate[i]);
		
		while (m --)
		{
			//out(rate, n + 1);
			int maxRate = rate[1], pos = 1;
			for (i = 2; i <= n; i ++)
			{
				if (rate[i] > maxRate)
				{
					maxRate = rate[i];
					pos = i;
				}
			}
			printf("%d\n", pos);
			for (j = 1; j <= n; j ++)
			{
				rate[j] += maxRate / (n - 1);
			}
			maxRate %= (n - 1);

			for (j = 1; j <= n && maxRate; j ++)
			{
				if (j == pos)	continue;
				rate[j] ++;
				maxRate --;
			}
			rate[pos] = 0;
		}		
	}
	return 0;
}