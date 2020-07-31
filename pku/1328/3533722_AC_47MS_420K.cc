//

#include <iostream>
#include <algorithm>
#include <math.h>
#define eps 1e-8
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
	return b.t - a.t > eps;
}

int input(){
	int i;	
	//memset(nd, 0, sizeof(nd[0]) * n);
	//memset(pt, 0, sizeof(pt[0]) * n);
	int flag = 1;
	for (i = 0; i < n;  i++)
	{
		scanf("%lf %lf", &pt[i].x, &pt[i].y);
		if (pt[i].y - d > eps)
		{
			flag=  0;
		}
	}
	if (0 == flag)	return 0;
	for (i = 0; i < n; i ++)
	{
		double tmp = sqrt((double)d * (double) d - pt[i].y * pt[i].y);
		nd[i].s = (double)pt[i].x - tmp;
		nd[i].t = (double)pt[i].x + tmp;
	}
	return 1;
}


void solve(){
	sort(nd, nd + n, cmp);
	int ans = 1;
	double cnt = nd[0].t;
	for (int i = 1; i < n; i ++)
		if (nd[i].s > cnt)
		{
			ans++;
			cnt = nd[i].t;
		}
	printf("Case %d: %d\n", testcase, ans);
}

int main(){
	testcase = 0;
	while (EOF != scanf("%d %d", &n, &d) && (n + d))
	{
		if (0 == n && 0 == d)	break;
		testcase ++;
		int flag = input();
		if (0 == flag)
		{
			printf("Case %d: -1\n", testcase);
		}
		else 
		{
			solve();
		}
	}
	return 0;
}