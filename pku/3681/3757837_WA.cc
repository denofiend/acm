//


#include <iostream>
#define MAXN 1010
#define Inf 0xffff
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void  out(T x, int n, int m){	for (int i = 0; i < n; i++)	cout(x[i], m);	cout << endl;	}

struct Point{
	int x, y;
	void operator =(const Point a){
		this->x = a.x;
		this->y = a.y;
	}
};

bool cmp1(const Point &a, const Point &b){
	return a.x > b.x;
}

bool cmp2(const Point &a, const Point &b){
	return a.y < b.y;
}

int n, m, area;
Point point[MAXN], heap1[MAXN], heap2[MAXN];

void calArea(Point *heap){
	int minx, maxx, miny, maxy;
	minx = maxx = heap[0].x;
	miny = maxy = heap[0].y;
	for (int i = 1; i < m; i ++)
	{
		if (minx > heap[i].x)	minx = heap[i].x;
		if (maxx < heap[i].x)	maxx = heap[i].x;
		if (miny > heap[i].y)	miny = heap[i].y;
		if (maxy < heap[i].y)	maxy = heap[i].y;
	}
	int diffx = maxx - minx + 2;
	int diffy = maxy - miny + 2;
	int newArea = diffx * diffy;
	if (area > newArea)
	{
		area = newArea;
	}
}
int main(){
	int i, t;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)	scanf("%d %d", &point[i].x, &point[i].y);
		area = Inf;
		for (i = 0; i < m; i ++)	heap1[i] = point[i], heap2[i] = point[i];
		calArea(heap1);

		for (; i < n; i ++)
		{
			heap1[m] = point[i];
			push_heap(heap1, heap1 + m + 1, cmp1);
			pop_heap(heap1, heap1 + m + 1, cmp1);
			calArea(heap1);

			heap1[m] = point[i];
			push_heap(heap1, heap1 + m + 1, cmp2);
			pop_heap(heap1, heap1 + m + 1, cmp2);
			calArea(heap1);
			
			heap2[m] = point[i];
			push_heap(heap2, heap2 + m + 1, cmp2);
			pop_heap(heap2, heap2 + m + 1, cmp2);
			calArea(heap2);
	
		}
		printf("%d\n", area);
	}	
	return 0;
}