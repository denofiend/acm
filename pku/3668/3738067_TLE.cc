//

#include <iostream>
#include <math.h>
#define eps 1e-8
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)


using namespace std;

struct Point{
	double x, y;
};

Point point[210];


int parallel(Point u1, Point u2 ,Point v1, Point v2){
	return zero((u1.x - u2.x) * (v1.y - v2.y)  - (v1.x - v2.x) * (u1.y - u2.y));
}

int main(){
	int n, ans;
	while (EOF != scanf("%d", &n))
	{
		int i, j, k, k1;
		for (i = 0; i < n; i ++)	scanf("%lf %lf", &point[i].x, &point[i].y);

		ans = n * (n - 1)  / 2;
	
		for (i = 0; i < n ; i ++)
		{
			for (j = i + 1; j < n ; j ++)
			{
				for (k = i + 1; k < n; k ++)
				{
					for (k1 = k + 1 ; k1 < n; k1 ++)
					{
						if (!(i != j && j != k && k != k1 && i != k && i != k1 && j != k1))	continue;
						//printf("[%d %d %d %d]\n", i, j, k, k1);
						if (parallel(point[i], point[j], point[k], point[k1]))
						{
							//printf("[%d %d %d %d]\n", i, j, k, k1);
							ans --;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}