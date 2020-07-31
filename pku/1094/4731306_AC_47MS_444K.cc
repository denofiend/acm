


#include <iostream>

using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for (int i = (int)a; i >= (int)b; --i)
int n, m;
int g[30][30];
char ans[30];


int main(){
	char from, to;
	int inco, sorted;
	while (cin >> n >> m)
	{
		if (0 == n && 0 == m)	break;
		memset(ans, 0, sizeof(ans));
		memset(g, 0, sizeof(g));	
		REP (i, n)	ans[i] = i+'A';
		ans[n] = '\0';
		inco = sorted = 0;
		REP (k, m)
		{
			cin >> from >> to >> to;
			
			if (inco || 0 !=  sorted)	continue;
 			g[from-'A'][to-'A'] = 1;			
			REP (k0, n)
				REP (i, n)
					REP (j, n)
						if (g[i][k0] && g[k0][j])
							g[i][j] = 1;
			
			REP (i, n)
				FOR (j, i+1, n)
				{
					if (!inco && g[i][j] && g[j][i])
					{
						cout << "Inconsistency found after " << k+1 << " relations." << endl;
						inco = 1;
						break;
					}
				}
			if (inco)	continue;
			
			int num = 0;
			REP (i, n)
				FOR (j, i+1, n)
					if (g[i][j] || g[j][i])	num++;
			
			if (num == n*(n-1)/2)	sorted = k+1;

		}

		if (inco)	continue;
		if (0 == sorted)	cout << "Sorted sequence cannot be determined." << endl;
		else
		{
			REP (i, n)
				FOR (j, i+1, n)
				if (g[ans[j]-'A'][ans[i]-'A'])
					swap(ans[j], ans[i]);
			cout << "Sorted sequence determined after " << sorted << " relations: " << ans << '.' << endl;
		}
	}
	return 0;
}

