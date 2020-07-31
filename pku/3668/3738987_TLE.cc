//

#include <iostream>
#include <math.h>
#include <map>
#include <string>
#include <vector>
#define eps 1e-8
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)


using namespace std;


template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}

struct Point{
	double x, y;
};

Point point[210];

int visited[210];
int pt[5];
int n, ans;
map<vector<int>, bool> hash;

int parallel(Point u1, Point u2 ,Point v1, Point v2){
	return zero((u1.x - u2.x) * (v1.y - v2.y)  - (v1.x - v2.x) * (u1.y - u2.y));
}


void dfs(int cnt){
	if (cnt == 4)
	{
		//out(pt, 4);
		vector<int> table;
		for (int i = 0; i < 4; i ++)
		{
			table.push_back(pt[i]);
		}
		sort(table.begin(), table.begin() + 1);
		sort(table.begin() + 2, table.end());
		if (hash.end() == hash.find(table))
		{
			if (parallel(point[ pt[0] ], point[ pt[1] ], point[ pt[2] ], point[ pt[3] ]))
				ans --;
			hash[table] = true;
		}
		return;
	}
	for (int i = 0; i < n; i ++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			pt[cnt] = i;
			
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}
}

int main(){	
	while (EOF != scanf("%d", &n))
	{
		int i, j, k, k1;
		for (i = 0; i < n; i ++)	scanf("%lf %lf", &point[i].x, &point[i].y);

		ans = n * (n - 1)  / 2;
		memset(visited, 0, sizeof(visited));
		visited[0] = 1;
		pt[0] = 0;
		hash.clear();
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}