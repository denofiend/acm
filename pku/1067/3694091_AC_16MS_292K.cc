// 1067(pku)
// 取石子游戏

#include <stdio.h>

#include <math.h>



int main()

{

	double alpha = (1.0 + sqrt(5.0)) / 2.0;

	double beta = (3.0 + sqrt(5.0)) / 2.0;

	int big, small, n, temp1, temp2;

	while (EOF != scanf("%d%d", &big, &small))

	{

		if (big < small)

		{

			n = big;

			big = small;

			small = n;

		}

		//n = (int)(big / beta-1e-8) + 1;

		n = ceil(small / alpha);		
		temp1 = alpha * n;

		temp2 = beta * n;
		//printf("n = %d, temp1 = %d, temp2 = %d\n", n, temp1, temp2);

		if (small == temp1 && big == temp2)

		{

			printf("0\n");

		}

		else

		{

			printf("1\n");

		}

	}

}


