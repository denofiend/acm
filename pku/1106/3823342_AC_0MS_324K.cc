//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-8
#define zero(x) (((x) > 0 ? (x) : - (x)) < eps)

#define MAXN 500


struct Point{
	double x, y, angle;
};

Point point[MAXN], s0, s;
double r;
const double PI = acos(-1);
int n;

double dis(const Point p1, const Point p2){
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void input(){
	int i, j;
	scanf("%d", &n);
	for (i = 0, j = 0; i < n; i ++)
	{
		scanf("%lf %lf", &s.x, &s.y);
		double d = dis(s, s0);
		if (d <= r)	point[j++] = s;
	}
	n = j;
}

double xmult(const Point p1, const Point p2, const Point p0){
	return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}

int cmp(const void *a, const void *b)

{

	Point *c = (Point *)a;

	Point *d = (Point *)b;

	if (fabs(c->angle - d->angle) < 1e-6)

	{

		return abs(c->x - point[0].x) - abs(d->x - point[0].x) + abs(c->y - point[0].y) - abs(d->y - point[0].y);

	}

	else if (c->angle > d->angle)

	{

		return 1;

	}

	else

	{

		return -1;

	}

}

void solve(){
	int i, j, t = 0;
	//double tmp;

	//for (i = 1; i < n; i ++)
	//{
	//	if (point[t].y > point[i].y || (zero(point[t].y - point[i].y) && point[t].x > point[i].x))
	//	{
	//		t = i;
	//	}
	//}
	//if (t != 0)
	//{
	//	tmp = point[0].x, point[0].x = point[t].x, point[t].x = tmp;
	//	tmp = point[0].y, point[0].y = point[t].y, point[t].y = tmp;
	//}
	
	///for (i = 1; i < n; i ++)
	//{
	//	point[i].angle = atan2(point[i].y - point[0].y, point[i].x - point[0].x);
	//}

	//qsort(point + 1, n - 1, sizeof(point[0]), cmp);

	int ans = 0, cnt;
	double o, dis1, dis2, dis3;
	for (i = 0; i < n; i ++)
	{
		for (j = 0, cnt = 0; j < n; j ++)
		{
			double ret = xmult(point[j], point[i], s0);
			if (ret <= 0)
			{
				cnt ++;
			}
		}
		if (cnt > ans)	ans = cnt;
	}
	printf("%d\n", ans);
}
int main(){
	while (EOF != scanf("%lf %lf %lf", &s0.x, &s0.y, &r))
	{
		if (r < 0)	break;
		input();
		solve();
	}
	return 0;
}

