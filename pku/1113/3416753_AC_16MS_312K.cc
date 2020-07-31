#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
	int x, y;
	double ang;
} Point;

Point p[1000];

int cmp(const void *a, const void *b)
{
	Point *c = (Point *)a;
	Point *d = (Point *)b;
	if (fabs(c->ang - d->ang) < 1e-6)
	{
		return abs(c->x - p[0].x) - abs(d->x - p[0].x) + abs(c->y - p[0].y) - abs(d->y - p[0].y);
	}
	else if (c->ang > d->ang)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int cross(int a, int b, int c)
{
	return (p[b].x - p[a].x) * (p[c].y - p[b].y) - (p[b].y - p[a].y) * (p[c].x - p[b].x);
}

int main()
{
	int i;
	int left, tmp;
	int r, n;
	int stack[1000], top;
	const double PI = acos(-1);
	double C;

	while (EOF != scanf("%d%d", &n, &r))
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &p[i].x, &p[i].y);
		}

		for (i = 1, left = 0; i < n; i++)
		{
			if (p[i].x < p[left].x)
			{
				left = i;
			}
			else if (p[i].x == p[left].x && p[i].y < p[left].y)
			{
				left = i;
			}
		}

		tmp = p[0].x;
		p[0].x = p[left].x;
		p[left].x = tmp;

		tmp = p[0].y;
		p[0].y = p[left].y;
		p[left].y = tmp;

		for (i = 1; i < n; i++)
		{
			p[i].ang = atan2(p[i].y - p[0].y, p[i].x - p[0].x);
		}

		qsort(p+1, n - 1, sizeof(p[0]), cmp);

		stack[0] = 0;
		stack[1] = 1;
		top = 1;

		for (i = 2; i < n; i++)
		{
			while (cross(stack[top-1], stack[top], i) < 0)
			{
				top--;
			}
			top++;
			stack[top] = i;
		}
		top++;

		for (i = 0, C = 0; i < top; i++)
		{
			C += sqrt( (p[stack[i]].x - p[stack[(i+1)%top]].x) * (p[stack[i]].x - p[stack[(i+1)%top]].x)
					+  (p[stack[i]].y - p[stack[(i+1)%top]].y) * (p[stack[i]].y - p[stack[(i+1)%top]].y) );
		}

		C += 2 * PI * r + 0.5;
		printf("%d\n", (int)C);

	}
	return 0;
}
