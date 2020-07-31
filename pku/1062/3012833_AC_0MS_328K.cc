#include <stdio.h>
#include <memory.h>
#define MAX 0x33333333
typedef struct
{
	int index;
	int money;
	int level;
}node;
int g[101][101],weight[101];
int m, n, ans = MAX, heapsize, minl, maxl;
node a[101];
node heap[10000];
bool v[101];
void fixup()
{
	node tmp = heap[heapsize];
	int i = heapsize,p;
	
	while (i > 1)
	{
		p = i >> 1;
		if (heap[p].money > tmp.money)
		{
			heap[i] = heap[p];
			i = p;
		}
		else break;
	}
	heap[i] = tmp;
}
void fixdown()
{
	node tmp = heap[1];
	int i = 1, l;
	while (i <= (heapsize >> 1))
	{
		l = i << 1;
		if (l < heapsize && heap[l].money > heap[l + 1].money) l++;
		if (tmp.money > heap[l].money)
		{
			heap[i] = heap[l];
			i = l;
		}
		else break;
	}
	heap[i] = tmp;
}
node getmin(){
	node ret = heap[1];
	heap[1] = heap[heapsize--];
	fixdown();
	return ret;
}
void heapadd(int index, int w){
	heap[++heapsize].index = index;
	heap[heapsize].money = w;
	fixup();
}
void input(){
	scanf("%d%d",&m,&n);
	int num, f, w;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].money, &a[i].level);
		a[i].index = i;
		g[0][i] = a[i].money;
		scanf("%d",&num);
		for (int j = 1; j <= num; j++)
		{
			scanf("%d%d", &f, &w);
			g[f][i] = w;
		}
	}
	g[0][0] = 0;
	a[0].index = 0; a[0].money = 0;
}
void initheap()
{
	memset(heap, 0, sizeof(heap));
	memset(weight, 0x33, sizeof(weight));
	memset(v, false, sizeof(v));
	heapsize=0;
}
int dijkstra(int s)
{
	initheap();
	node min;
	maxl = a[s].level;
	minl = a[s].level- m > 0 ? (a[s].level - m) : 0;
	heap[1] = a[0];
	weight[0] = 0;
	heapsize = 1;
	while (heapsize > 0)
	{
		min = getmin();
		if (!v[min.index])
		{
			v[min.index] = true;
			for (int i = 1; i <= n; i++)
			{
				if (!v[i] && a[i].level >= minl && a[i].level <= maxl && g[min.index][i] != -1 && weight[min.index] + g[min.index][i] < weight[i])
				{
					weight[i] = weight[min.index] + g[min.index][i];
					heapadd(i, weight[i]);
				}
			}
		}
		if(min.index == 1) break;
	}
	return weight[1];
}
void init()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++) 
			g[i][j] = -1;
}
int main()
{
	init();
	input();
	for(int s = 1; s <= n; s++)
	{
		int tmp = dijkstra(s);
		ans = ans < tmp ? ans : tmp;
	}
	printf("%d\n", ans);
	return 0;
}