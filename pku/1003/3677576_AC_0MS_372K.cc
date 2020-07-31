//

#include <iostream>

using namespace std;


int main(){
	double c, sum;
	int i;
	while (EOF != scanf("%lf", &c))
	{
		if (0.0 == c)	break;
			
		for (i = 1, sum = 0; sum <= c; i ++)
		{
			sum += 1.0 / (i + 1);
		}
		printf("%d card(s)\n", i - 1);
	}
	return 0;
}