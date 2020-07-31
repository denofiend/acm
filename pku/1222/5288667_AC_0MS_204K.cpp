#include <stdio.h>

#include <memory.h>



int m[7][8], d[7][8], tmp[7][8];



int check(int X)

{

	int i, j;

	memset(d, 0, sizeof(d));

	memcpy(tmp, m, sizeof(m));

	for (i = 1; i <= 5; i++)

	{

		if (X & (1 << (i - 1)))

		{

			d[i][1] = 1;

			tmp[i][1] = !tmp[i][1];

			tmp[i - 1][1] = !tmp[i - 1][1];

			tmp[i][2] = !tmp[i][2];

			tmp[i + 1][1] = !tmp[i + 1][1];

		}

	}

	for (j = 2; j <= 6; j++)

	{

		for (i = 1; i <= 5; i++)

		{

			if (tmp[i][j - 1])

			{

				d[i][j] = 1;

				tmp[i][j] = !tmp[i][j];

				tmp[i - 1][j] = !tmp[i - 1][j];

				tmp[i + 1][j] = !tmp[i + 1][j];

				tmp[i][j - 1] = !tmp[i][j - 1];

				tmp[i][j + 1] = !tmp[i][j + 1];

			}

		}

	}

	for (i = 1; i <= 5; i++)

	{

		if (tmp[i][6])

			return 0;

	}

	return 1;

}



void Solve()

{

	int i, j;

	memset(m, 0, sizeof(m));

	for (i = 1; i <= 5; i++)

		for (j = 1; j <= 6; j++)

			scanf("%d", &m[i][j]);

	for (i = 0; i < 32; i++)

		if (check(i))

			break;

	for (i = 1; i <= 5; i++)

	{

		for (j = 1; j <= 6; j++)

			printf("%d ", d[i][j]);

		printf("\n");

	}

}



int main()

{

	int T, t;

	scanf("%d", &T);

	t = 1;

	while (T--)

		printf("PUZZLE #%d\n", t++),

		Solve();

	return 0;

}


