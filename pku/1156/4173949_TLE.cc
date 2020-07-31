
#include <stdio.h>
int m, n, c, i, j, rmin[700], rmax[700], min, max, k, up, down, marea, temp;
int index[62000], d[700][700];

void input(){
	scanf("%d%d%d", &n, &m, &c);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", &d[i][j]);
			//d[i][j] += 30001;
		}
}

int main(){
	input();
	for (int j1 = 0; j1 < n; j1++)
	{
		for (i = 0; i < m; i++)
			rmin[i] = rmax[i] = d[i][j1];

		for (int j2 = j1; j2 < n && j2 - j1 < 100; j2++)
		{
			min = 60002;
			max = 0;
			up = 0;
			down = -1;
			for (i = 0; i < m; i++)
			{
				if (d[i][j2] > rmax[i]) rmax[i] = d[i][j2];
				if (d[i][j2] < rmin[i]) rmin[i] = d[i][j2];
				if (rmax[i] - rmin[i] > c)
				{
					up = i+1;
					continue;
				}
				if (rmax[i] - min > c)
				{
					for (k = min; k < rmax[i] - c && k <= max; k++)
						if (index[k] >= up && index[k] <= down)
							if (k == rmin[index[k]])
								up = index[k] + 1;
					min = 60002;
					for (k = rmax[i] - c; k < rmax[i]; k++)
						if (index[k] >= up && index[k] <= down)
							if (k == rmin[index[k]])
							{
								min = k;
								break;
							}

				}
				if (max - rmin[i] > c)
				{
					for (k = max; k > rmin[i] + c && k >= min; k--)
						if (index[k] >= up && index[k] <= down)
							if (k == rmax[index[k]])
								up = index[k]+1;
					max = 0;
					for (k = rmin[i] + c; k > rmin[i]; k--)
						if (index[k] >= up && index[k] <= down)
							if (k == rmax[index[k]])
							{
								max = k;
								break;
							}

				}

				if (rmax[i] > max) max = rmax[i];
				if (rmin[i] < min) min = rmin[i];
				index[rmax[i]] = index[rmin[i]] = i;
				down = i;
				if ((temp = (down - up + 1) * (j2 - j1 + 1)) > marea) marea = temp;
			}
		}
	}
	printf("%d\n",marea);
	return 0;
}
