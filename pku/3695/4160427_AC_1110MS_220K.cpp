
#include <stdio.h>
#define MAXN 500000
#define MAX(a, b)   a > b ? a : b;
#define MIN(x, y)   x < y ? x : y;

struct Node{
	int llx, lly;
	int urx, ury;
	int tag;
};

Node rect[MAXN];

void solve(int i, int j, int &rectl){

	if(rect[i].llx >= rect[j].urx) return ;
	if(rect[j].llx >= rect[i].urx) return ;
	if(rect[i].lly >= rect[j].ury) return ;
	if(rect[j].lly >= rect[i].ury) return ;
	rect[rectl].llx = MAX(rect[i].llx, rect[j].llx);
	rect[rectl].lly = MAX(rect[i].lly, rect[j].lly);
	rect[rectl].urx = MIN(rect[i].urx, rect[j].urx);
	rect[rectl].ury = MIN(rect[i].ury, rect[j].ury);
	rect[rectl].tag = -rect[j].tag;
	rectl++;
}

int main(){
	Node input[30];
	int a, num, test = 1, ca;
	int n, m, rectl, tail, sum;
	while(scanf("%d%d", &n, &m) != EOF && (n || m))
	{
		for(int i = 1;i <= n;i++)
			scanf("%d%d%d%d", &input[i].llx, &input[i].lly, &input[i].urx, &input[i].ury);
		printf("Case %d:\n", test++);
		ca = 1;
		for(int k = 1;k <= m;k++)
		{
			scanf("%d", &num);
			rectl = 0;
			for(int i = 1;i <= num;i++)
			{
				scanf("%d", &a);
				rect[rectl] = input[a];
				rect[rectl].tag = 1;
				tail = rectl;
				rectl++;
				for(int j = 0;j <= tail - 1;j++)
				{
					solve(tail, j, rectl);
				}
			}
			sum = 0;
			for(int i = 0;i < rectl;i++)
				sum += (rect[i].urx - rect[i].llx) * (rect[i].ury - rect[i].lly) * rect[i].tag;
			printf("Query %d: %d\n", ca++, sum);
		}
		printf("\n");
	}
	return 0;
}
