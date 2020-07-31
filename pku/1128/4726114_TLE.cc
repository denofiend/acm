


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for (int i = (int)a; i >= (int)b; --i)


char maze[30][30], tmp[30][30];
int lx[300], ly[300], rx[300], ry[300];
int n, m, vis[30];
string str;

bool okk(char c){
	FOR (i, lx[c], rx[c]+1)
		if (!(c == tmp[i][ly[c]] || '.' == tmp[i][ly[c]]) || !(c == tmp[i][ry[c]] || '.' == tmp[i][ry[c]]))	return false;
	FOR (i, ly[c], ry[c]+1)
		if (!(c == tmp[lx[c]][i] || '.' == tmp[lx[c]][i]) || !(c == tmp[rx[c]][i] || '.' == tmp[rx[c]][i]))	return false;
	return true;
}

bool ok(string str){
	REP (i, n)
		REP (j, m)
			tmp[i][j] = maze[i][j];

	FORD (k, str.size()-1, 0)
	{
		if (okk(str[k]))
		{
			REP (i, n)
				REP (j, m)
					if (str[k] == tmp[i][j])	tmp[i][j] = '.';
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main(){
	while (cin >> n >> m)
	{
		memset(lx, -1, sizeof(lx));
		memset(ly, -1, sizeof(ly));
		memset(rx, -1, sizeof(rx));
		memset(ry, -1, sizeof(ry));
		memset(vis, 0, sizeof(vis));
		str.clear();

		REP (i, n)
			REP(j, m)
			{
				cin >> maze[i][j];
				if ('.' != maze[i][j])
				{

					if (!vis[maze[i][j]-'A'])
					{
						str += maze[i][j];
						vis[maze[i][j]-'A'] = 1;
					}
					if (-1 == lx[maze[i][j]] || lx[maze[i][j]] > i)	lx[maze[i][j]] = i;
					if (-1 == ly[maze[i][j]] || ly[maze[i][j]] > j)	ly[maze[i][j]] = j;
					if (-1 == rx[maze[i][j]] || rx[maze[i][j]] < i)	rx[maze[i][j]] = i;
					if (-1 == ry[maze[i][j]] || ry[maze[i][j]] < j)	ry[maze[i][j]] = j;
				}
			}
		sort(str.begin(), str.end());
		vector<string> ans;
		do
		{
			if (ok(str))	ans.push_back(str);
		}
		while (next_permutation(str.begin(), str.end()));

		REP (i, ans.size())
			cout << ans[i] << endl;
	}
	return 0;
}
