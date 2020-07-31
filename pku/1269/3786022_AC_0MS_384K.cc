//

//浮点几何函数库
#include <iostream>
#include <math.h>
#define eps 1e-8
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)
using namespace std;


struct Point{double x, y;};



//计算cross product (P1-P0)x(P2-P0)
double xmult(Point p1, Point p2, Point p0){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int dots_inline(Point p1, Point p2, Point p3){
	return zero(xmult(p1, p2, p3));
}

//判两直线平行
int parallel(Point u1, Point u2, Point v1, Point v2){
	return zero((u1.x - u2.x) * (v1.y - v2.y) - (v1.x - v2.x) * (u1.y - u2.y));
}


// 计算两直线交点,注意事先判断直线是否平行!
// 线段交点请另外判线段相交(同时还是要判断是否平行!)

Point intersection(Point u1, Point u2, Point v1, Point v2){
	Point ret = u1;
	double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x -v2.x))
			/ ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y-u2.y) * (v1.x-v2.x));
	ret.x += (u2.x - u1.x) * t;
	ret.y += (u2.y - u1.y) * t;
	return ret;
}


#include <iostream>

using namespace std;


int main(){
	Point p1, p2, p3, p4, intersect;
	int t, i;
	scanf("%d", &t);
	printf("INTERSECTING LINES OUTPUT\n");
	while (t --)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x,&p4.y);
		if (parallel(p1, p2, p3, p4))
		{
			if (dots_inline(p1, p2, p3) && dots_inline(p1, p2, p4))
			{
				printf("LINE\n");
			}
			else
			{
				printf("NONE\n");
			}
		}
		else
		{
			intersect = intersection(p1, p2, p3, p4);
			printf("POINT %.2lf %.2lf\n", intersect.x, intersect.y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}