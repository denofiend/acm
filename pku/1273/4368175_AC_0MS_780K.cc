

//
//
#include <iostream>

using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for (int i = (int)a; i >= (int)b; --i)
#define MAXN 220
#define Inf 10000000

int f[MAXN][MAXN], c[MAXN][MAXN];
int pre[MAXN], q[MAXN*2], v[MAXN];
int s, t, n, m;


int maxflow(){
	int head, tail, i, j;
	while (true)
	{
		memset(pre, 0, sizeof(pre));
		head = tail = 0;
		q[tail++] = s;
		pre[s] = s;
		v[s] = Inf;

		while (head < tail && 0 == pre[t])
		{
			i = q[head++];
			for (j = 1; j <= t; ++j)
			{
				if (0 == pre[j])
				{
					if (f[i][j] < c[i][j])
					{
						pre[j] = i;
						q[tail++] = j;
						v[j] = min(v[i], c[i][j]-f[i][j]);
					}
					else if (f[j][i] > 0)
					{
						pre[j] = -i;
						q[tail++] = j;
						v[j] = min(v[i], f[j][i]);
					}
				}
			}
		}

		if (0 == pre[t])	break;
	
		i = t;
		while (i != s)
		{
			j = abs(pre[i]);
			
			if (pre[i] > 0)	f[j][i] += v[t];
			else f[i][j] -= v[t];
			i = j;
		}
	}

	int ret = 0;
	for (i = 1; i <= t; ++i)	ret += f[s][i];
	return ret;
}

int main(){
	int sta, end, val;
	while (EOF != scanf("%d%d", &m, &n))
	{
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		s = 1, t = n;

		REP (i, m)
		{
			scanf("%d%d%d", &sta, &end, &val);
			c[sta][end] += val;
		}
		printf("%d\n", maxflow());
	}
	return 0;
}
