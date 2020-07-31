//

#include <iostream>
#include <math.h>
using namespace std;

int main(){
	double ans, R, c, w, vs;
	int n;
	scanf("%lf %lf %lf", &vs, &R, &c);
	scanf("%d", &n);
	while (n --)
	{
		scanf("%lf", &w);
		ans = R * c * w * vs * sin(atan( 1 / R / c / w));
		printf("%.3lf\n", ans);
	}
	return 0;
}