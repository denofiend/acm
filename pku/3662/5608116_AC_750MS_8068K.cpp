//

//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

template <class T> void out(T x, int n){	for(int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for(int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)

#define MAXN 2001
#define Inf 0x7fffffff

int g[MAXN][MAXN];
int n, m, k;
int w[MAXN*MAXN];
int dist[MAXN];
int vis[MAXN];

int cal(int val){
	REP (i, n)	vis[i] = 0, dist[i] = Inf;

	dist[0] = 0;
	REP (i, n)
	{
		int k = -1;
		REP (j, n)
		{
			if (!vis[j] && (-1 == k || dist[j] < dist[k]))
			{
				k = j;
			}
		}
		if (-1 == k)	break;
		vis[k] = 1;
		REP (j, n)
		{
			if (!vis[j] && g[k][j] && Inf != dist[k])
			{
				if (dist[k] + (g[k][j] > val) < dist[j])
					dist[j] = dist[k] + (g[k][j] > val);
			}
		}
	}
	return dist[n-1];
}

int main(){
	int s, e, lo, hi, mid, cnt, mm;
	while (EOF != scanf("%d %d %d", &n, &m, &k))
	{
		REP (i, n)
		{
			REP (j, m)
			{
				g[i][j] = 0;
			}
		}


		REP (i, m)
		{
			scanf("%d %d %d", &s, &e, &w[i]);
			s--;
			e--;
			g[s][e] = g[e][s] = w[i];	
		}
		sort(w, w+m);

		lo = 0, hi = m;

		while (lo < hi)
		{
			mid = lo + (hi - lo) / 2;
			cnt = cal(w[mid]);
			if (cnt <= k)	hi = mid;
			else lo = mid + 1;
		}
		cnt = cal(w[lo]);
		//OUT(cnt);
		if (cnt == k)	printf("%d\n", w[lo]);
		else if (cnt < k)	printf("0\n");
		else printf("-1\n");
		
	}
	return 0;
}
