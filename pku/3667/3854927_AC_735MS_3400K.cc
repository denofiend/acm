//
#include <assert.h>
#include <stdio.h>
#include <algorithm>

int realn;
int n;

enum { EMPTY, FULL, MIXED };

struct node {
    char state;
    int lmax;
    int rmax;
    int cmax;

    int start;
    unsigned size;
};

const int NMAX = 2*160000+1;
const int ROOT = 1;
node tree[NMAX];

inline int left(int v) { return 2*v; }
inline int right(int v) { return 2*v+1; }
inline int parent(int v) { return v/2; }

inline unsigned size(int v) { return tree[v].size; }
inline int start(int v) { return tree[v].start; }
inline int end(int v) { return start(v) + size(v); }

void propogate(int v) {
	if (left(v) >= 2 * n) return;
	if (tree[v].state == EMPTY) 
	{
		unsigned s = size(left(v));
		tree[left(v)].state = EMPTY;
		tree[left(v)].lmax = s;
		tree[left(v)].rmax = s;
		tree[left(v)].cmax = s;
		tree[right(v)].state = EMPTY;
		tree[right(v)].lmax = s;
		tree[right(v)].rmax = s;
		tree[right(v)].cmax = s;
    	} 
	else if (tree[v].state == FULL) 
	{
		tree[left(v)].state = FULL;
		tree[left(v)].lmax = 0;
		tree[left(v)].rmax = 0;
		tree[left(v)].cmax = 0;
		tree[right(v)].state = FULL;
		tree[right(v)].lmax = 0;
		tree[right(v)].rmax = 0;
		tree[right(v)].cmax = 0;
   	 }
}

void inherit(int v) { // assert - left & right are up-to-date
	if (left(v) >= 2 * n) return;
	if (tree[left(v)].state == EMPTY
	    && tree[right(v)].state == EMPTY) 
	{
		tree[v].state = EMPTY;
		tree[v].lmax = tree[v].rmax = tree[v].cmax = size(v);
		return;
	}
	if (tree[left(v)].state == FULL
	    && tree[right(v)].state == FULL) 
	{
		tree[v].state = FULL;
		tree[v].lmax = tree[v].rmax = tree[v].cmax = 0;
		return;
	}

	tree[v].state = MIXED;

	tree[v].lmax = tree[left(v)].lmax;
	if (tree[left(v)].state == EMPTY)
	tree[v].lmax = tree[right(v)].lmax + size(left(v));

	tree[v].rmax = tree[right(v)].rmax;
	if (tree[right(v)].state == EMPTY)
	tree[v].rmax = tree[left(v)].rmax + size(right(v));

	tree[v].cmax = std::max(std::max(
		tree[left(v)].cmax, tree[right(v)].cmax),
	tree[left(v)].rmax + tree[right(v)].lmax);
}

int query(int d, int v) {
    if (v >= 2*n) return -1;
    if (tree[v].state == EMPTY && tree[v].size <= d) return tree[v].start;
    propogate(v);
    if (tree[left(v)].cmax >= d) return query(d, left(v));
    if (tree[left(v)].rmax + tree[right(v)].lmax >= d) return
end(left(v))-tree[left(v)].rmax;
    if (tree[right(v)].cmax >= d) return query(d, right(v));
    return -1;
}

void fill(int a, int b, int v) {
    //printf("f %d %d\n", a,b);
    int s = start(v);
    int e = end(v) - 1;
    if (v >= 2 * n || b < a || s > b || e < a) return;
    propogate(v);
    if (s >= a && e <= b) {
	tree[v].state = FULL;
	tree[v].lmax = tree[v].rmax = tree[v].cmax = 0;
	return;
    }
    fill(a,b, left(v));
    fill(a,b, right(v));
    inherit(v);
}
void empty(int a, int b, int v) {
    //printf("e %d %d\n", a,b);
    int s = start(v);
    int e = end(v)-1;
    if (v >= 2*n || b < a || s > b || e < a) return;
    propogate(v);
    if (s >= a && e <= b) {
	tree[v].state = EMPTY;
	tree[v].lmax = tree[v].rmax = tree[v].cmax = size(v);
	return;
    }
    empty(a,b, left(v));
    empty(a,b, right(v));
    inherit(v);
}

int main() {
	int m;
	scanf("%d %d\n", &realn, &m);
	n = 1; 
	while (n < realn) n *= 2;

	for (int i = n; i < 2 * n; i++) 
	{
		tree[i].size = 1;
		tree[i].start = i - n;
	}
	for (int i = n - 1; i > 0; i--) 
	{
		tree[i].size = 2 * tree[left(i)].size;
		tree[i].start = tree[left(i)].start;
	}

	for (int i = 1; i < 2 * n; i++)
	{
		tree[i].state = EMPTY;
		tree[i].lmax = size(i);
		tree[i].rmax = size(i);
		tree[i].cmax = size(i);
	}
	fill(realn, n - 1, ROOT);

	for (int i = 0; i < m; i++) 
	{
		int type;
		scanf("%d", &type);
		if (type == 1) 
		{
		    int d;
		    scanf("%d", &d);
		    int p = query(d, ROOT);
		    printf("%d\n", p + 1);
		    if (p >= 0)
			fill(p, p+d-1, ROOT);
		} 
		else 
		{
			int x, d;
			scanf("%d %d", &x, &d); 
			x--;
    			empty(x, x+d-1, ROOT);
		}
	}

	return 0;
}
