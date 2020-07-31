//


#include <iostream>
#include <math.h>
#define MAXN 220
#define Inf 0xffffff
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i] << ' ';	cout << endl;	}


int visited[MAXN];
int id[MAXN];
int area, n, m;
struct Point{
	int x, y;
};
Point point[MAXN];

void solve(){
	int i;
	int minx = point[ id[0] ].x, maxx, miny = point[ id[0] ].y, maxy;
	maxx = minx, maxy = miny;
	//out(id, m);
	for (i = 1; i < m; i++)
	{

		if (minx > point[ id[i] ].x)	minx = point[ id[i] ].x;
		if (maxx < point[ id[i] ].x)	maxx = point[ id[i] ].x;
		if (miny > point[ id[i] ].y)	miny = point[ id[i] ].y;
		if (maxy < point[ id[i] ].y)	maxy = point[ id[i] ].y;
	}
	int diffx = maxx - minx + 2;
	int diffy = maxy - miny + 2;
	int newArea = diffx * diffy;
	//printf("[%d %d %d]\n", diffx, diffy, newArea);
	if (area > newArea)
	{
		area = newArea;
	}
}

void dfs(int cnt, int pos){
	if (cnt == m)
	{
		solve();
		return;
	}
	for (int i = pos; i < n; i ++)
	{
		if (!visited[i])
		{
			id[cnt] = i;
			visited[i] = 1;
			dfs(cnt + 1, pos + 1);
			visited[i] = 0;
		}
	}
} 
int main(){
	int t, i;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)	scanf("%d %d", &point[i].x, &point[i].y);

		memset(visited, 0, sizeof(int) * n);
		area = Inf;
		
		dfs(0, 0);
		printf("%d\n", area);

	}
	return 0;
}