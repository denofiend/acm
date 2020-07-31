


#include <iostream>
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

	REP (i, lx+1)
		REP (j, ly+1)
			if (c == maze[i][j] && (i < lx || j < ly))
			{
				lx = i;
				ly = j;
			}	

	FOR (i, rx, n)
		FOR (j, ry, m)
			if (c == maze[i][j])
			{
				rx = i;
				ry = j;
			}

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
		vector<char> ans;
		while (1)
		{
			int cnt = 0;
			for (char c = 'A'; c <= 'Z'; ++ c)
			{
				if (ok(c))
				{
					REP (i, n)
						REP (j, m)
							if (c == maze[i][j])	maze[i][j] = '.';

					ans.push_back(c);
					//out(maze, n, m);
					break;
				}
				else	cnt++;
			}
			if (cnt == 26)	break;
		}
		FORD (i, ans.size()-1, 0)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}
