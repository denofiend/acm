
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for (int i = (int)a; i >= (int)b; --i)

char maze[35][35];
int n, m;


bool inMaze(const int &x, const int &y){
	return 0 <= x < n && 0 <= y && y < m;
}


bool ok(char c){
	int lx = -1, ly, rx, ry;
	REP (i, n)
		REP (j, m)
			if (c == maze[i][j])	lx = rx = i, ly = ry = j;

	if (-1 == lx)	return false;
	int lx0, ly0, rx0, ry0;
	
	//OUT(c);
	lx0 = lx;
	REP (i, lx+1)
		REP (j, m)
			if (c == maze[i][j] && lx0 > i)	lx0 = i;
	lx = lx0;

	ly0 = ly;		
	REP (i, n)
		REP (j, ly+1)
			if (c == maze[i][j] && ly0 > j)	ly0 = j;
	ly = ly0;

	rx0 = rx;
	FOR (i, rx, n)
		REP (j, m)
			if (c == maze[i][j] && rx0 < i)	rx0 = i;
	rx = rx0;

	ry0 = ry;
	REP (i, n)
		FOR (j, ry, m)
			if (c == maze[i][j] && ry0 < j)	ry0 = j;
	ry = ry0;


	//printf("%c -> [%d %d],<%d, %d>\n", c, lx, ly, rx, ry);

	FOR (i, lx, rx+1)
	{
		if (!(c == maze[i][ly] || '.' == maze[i][ly]) || !(c == maze[i][ry] || '.' == maze[i][ry]))	return false;
	}

	FOR (i, ly, ry+1)
	{
		if (!(c == maze[lx][i] || '.' == maze[lx][i]) || !(c == maze[rx][i] || '.' == maze[rx][i]))	return false;
	}
	return true;

}


int main(){
	while (cin >> n >> m)
	{
		REP (i, n)
			REP (j, m)
				cin >> maze[i][j];
		//out(maze, n, m);
		vector<string> ans;
		while (1)
		{
			int cnt = 0;
			string s0;
			for (char c = 'A'; c <= 'Z'; ++c)
				if (ok(c))
					s0 += c;
			//OUT(s0);
			if (0 == s0.size())	break;
			else
			{
				vector<string> tmp = ans;
				ans.clear();
				do
				{
					vector<string> tmp0 = tmp;
					if (0 == tmp0.size())	tmp0.push_back(s0);
					else
					{
						REP (i, tmp0.size())
							tmp0[i] += s0;
					}
					REP (i, tmp0.size())
						ans.push_back(tmp0[i]);
				}
				while (next_permutation(s0.begin(), s0.end()));
				REP (k, s0.size())
				{
					REP (i, n)
						REP (j, m)
							if (s0[k] == maze[i][j])	maze[i][j] = '.';
				}
				//out(maze, n, m);
				//out(ans, ans.size());
			}
		}

		sort(ans.begin(), ans.end());
		FORD (i, ans.size()-1, 0)
		{
			FORD (j, ans[i].size()-1, 0)
				cout << ans[i][j];
			cout << endl;
		}
	}
	return 0;
}
