//

#include <iostream>
#include <math.h>
#define MAXN  10010
using namespace std;

struct Node{
	double s, t;
};
Node nd[MAXN];

struct Point{
	double x, y;
};

Point pt[MAXN];

int n, d, testcase;

bool cmp(const Node &a, const Node &b){
	return a.t < b.t;
}

void input(){
	int i;
	for (i = 0; i < n;  i++)
		scanf("%lf %lf", &pt[i].x, &pt[i].y);
	
	for (i = 0; i < n; i ++)
	{
		double tmp = sqrt((double)d * d - pt[i].y * pt[i].y);
		nd[i].s = -pt[i].x - tmp;
		nd[i].t = -pt[i].x + tmp;
	}

	//for (i = 0; i < n; i ++)
	//	printf("%lf %lf\n", nd[i].s, nd[i].t);
}


void solve(){
	sort(nd, nd + n, cmp);
	int ans = 1, cnt = nd[0].t;
	for (int i = 1; i < n; i ++)
		if (nd[i].s > cnt)
		{
			ans ++;
			cnt = nd[i].t;
		}
	printf("Case %d: %d\n", testcase, ans);
}

int main(){
	testcase = 0;
	while (2 == scanf("%d %d", &n, &d))
	{
		if (0 == n && 0 == d)	break;
		testcase ++;
		input();
		solve();
	}
	return 0;
}