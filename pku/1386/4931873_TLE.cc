//


#include <iostream>

using namespace std;


template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " =  " << x << endl)
#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for (int i = (int)a; i >= (int)b; --i)
#define MAXN 26

int in[MAXN], ou[MAXN], g[MAXN][MAXN];
int n;
int visited[MAXN];

void input(){
	cin >> n;
	string str;
	memset(in, 0, sizeof(in));
	memset(ou, 0, sizeof(ou));
	memset(g, 0, sizeof(g));
	REP (i, n)
	{
		cin >> str;
		g[str[0]-'a'][str[str.size()-1]-'a'] = 1;
		ou[str[0]-'a']++;
		in[str[str.size()-1]-'a']++;	
	}
	//out(in, MAXN);
	//out(ou, MAXN);
}

void dfs(int e){
	visited[e] = 1;
	for (int i = 0; i < MAXN; i ++)
		if (!visited[i] && g[e][i])
			dfs(i);
}

bool connect(int e){
	memset(visited, 0, sizeof(visited));
	dfs(e);
	for (int i = 0; i < MAXN; i ++)
		if (0 == visited[i] && in[i] + ou[i] > 0)   return false;
	return true;
}

bool ok(){
	int flag = 0;
	REP (i, MAXN)
		if (in[i] + ou[i] > 0)
			if (connect(i))
			{
				flag = 1; 
				break;
			}
	if (0 == flag)	return false;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	REP (i, MAXN)
	{
		if (in[i] != ou[i])
		{
			if (1 == ou[i] - in[i])
			{
				cnt1++;
			}
			else if (1 == in[i] - ou[i])
			{
				cnt2 ++;
			}
			else
			{
				cnt3++;
				break;
			}
		}
	}

	return  !(1 < cnt1 || cnt1 != cnt2 || cnt3);
}

int main(){
	int t;
	cin >> t;
	while (t--)
	{
		input();
		if (ok())	cout << "Ordering is possible." << endl;
		else cout << "The door cannot be opened." << endl;
	}
	return 0;
}
