

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR (i, 0, b)
#define FORD(i, a, b)	for (int i = (int)a; i >= (int)b; --i)


char maze[30][30];
int n, m, total;
vector<string> ans;
char p[30];
int lx[200], ly[200], rx[200], ry[200];
int vis[30];

bool ok(char c){
	FOR (i, lx[c], rx[c]+1)
		if (!(c == maze[i][ly[c]] || '.' == maze[i][ly[c]]) || !(c == maze[i][ry[c]] || '.' == maze[i][ry[c]]))	return false;
	FOR (i, ly[c], ry[c]+1)
		if (!(c == maze[lx[c]][i] || '.' == maze[lx[c]][i]) || !(c == maze[rx[c]][i] || '.' == maze[rx[c]][i]))	return false;
	return true;
}

void dfs(int k){
	if (k == total)
	{
		p[n] = '\0';
		ans.push_back(p);
		return;
	}

	for (char c = 'A'; c <= 'Z'; ++c)
	{
		if (!vis[c-'A'] && ok(c))
		{
			char tmp[30][30];
			REP (i, n)
				REP (j, m)
					tmp[i][j] = maze[i][j];
			REP (i, n)
				REP (j, m)
					if (c == maze[i][j])	maze[i][j] = '.';
			p[total-1-k] = c;
			vis[c-'A'] = 1;
			dfs(k+1);
			vis[c-'A'] = 0;
			REP (i, n)
				REP (j, m)
					maze[i][j] = tmp[i][j];
		}
	}
}


int main(){
	while (cin >> n >> m)
	{
		memset(lx, -1, sizeof(lx));
		memset(ly, -1, sizeof(ly));
		memset(rx, -1, sizeof(rx));
		memset(ry, -1, sizeof(ry));
		memset(p, 0, sizeof(p));
		memset(vis, 0, sizeof(vis));
		ans.clear();
		total = 0;

		REP (i, n)
			REP (j, m)
			{
				cin >> maze[i][j];
				if ('.' != maze[i][j])
				{
					if (!vis[maze[i][j]-'A'])
					{
						total++;
						vis[maze[i][j]-'A'] = 1;
					}
					if (-1 == lx[maze[i][j]] || lx[maze[i][j]] > i)	lx[maze[i][j]] = i;
					if (-1 == ly[maze[i][j]] || ly[maze[i][j]] > j)	ly[maze[i][j]] = j;
					if (-1 == rx[maze[i][j]] || rx[maze[i][j]] < i)	rx[maze[i][j]] = i;
					if (-1 == ry[maze[i][j]] || ry[maze[i][j]] < j)	ry[maze[i][j]] = j;
				}
			}

		memset(vis, 0, sizeof(vis));	
		dfs(0);	

		sort(ans.begin(), ans.end());
		REP (i, ans.size())
			 cout << ans[i] << endl;
	}
	return 0;
}

