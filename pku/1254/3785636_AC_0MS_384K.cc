//
//
//
//

#include <iostream>
#include <math.h>
using namespace std;


int main(){
	int t;
	double x1, y1, x2, y2, k1, k2, degree1, degree2, x, y;
	const double PI = acos(-1);
	scanf("%d", &t);
	while (t --)
	{
		scanf("%lf %lf %lf", &x1, &y1, &degree1);
		scanf("%lf %lf %lf", &x2, &y2, &degree2);

		k1 = tan((450 - degree1) * PI / 180);
		k2 = tan((450 - degree2) * PI / 180);

		x = (k1 * x1 - k2 * x2 + y2 - y1) / (k1 - k2);

		y = (k1* k2 * (x1 - x2) + k1 * y2 - k2 * y1) / (k1 - k2);

		printf("%.4lf %.4lf\n", x, y);
	}
	return 0;
}