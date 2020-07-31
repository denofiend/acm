// 1151(pku)
// zab08
// SegmentTree 

#include <stdlib.h>
#include <stdio.h>
#define LINEM 201
struct Line{
	double x, y1, y2;
	int in;			// in = 1 矩形的左边； in = -1 矩形的右边
};

Line line[LINEM];
double y[LINEM];

struct Segment_node{
	int iL, iR, in;
	double left, right, y_len;
	Segment_node *pl, *pr;
	Segment_node();
};
class SegmentTree : public Segment_node, Line{
private:
	Segment_node *root;
	Segment_node* buildTree(int, int);
	void upDatahelp(Segment_node*, Line);
	double lengthhelp(Segment_node*);
public:
	SegmentTree():root(NULL){	}
	SegmentTree(const int, const int);
	void upData(Line);
	double length();
};
Segment_node::Segment_node(){
	iL = iR = in = 0;
	left = right = y_len = 0.0;
	pl = pr = NULL;
}
Segment_node* SegmentTree::buildTree(int left, int right){
	Segment_node* link = new Segment_node;
	link->iL = left, link->iR = right;
	link->left = y[left], link->right = y[right];
	if ( left + 1 < right )
	{
		int mid = (left + right) / 2;
		link->pl = SegmentTree::buildTree(left, mid);
		link->pr = SegmentTree::buildTree(mid, right);
	}
	return link;
}
SegmentTree::SegmentTree(int left, int right){	root = buildTree(left, right);	}
void SegmentTree::upData( Line ll){	upDatahelp(root, ll);	}
void SegmentTree::upDatahelp(Segment_node* link, Line ll){	
	if ( link->left == ll.y1 && link->right == ll.y2 )
	{
		link->in += ll.in;
		lengthhelp(link);
		//printf("{ link = %p, (link->iL = %d, link->iR = %d), (link->left = %lf, link->right = %lf), link->in = %d } \n", link->iL, link->iR, link->left, link->right, link->in);
		return;
	}
	if ( 1 >= link->iR - link->iL )
		return;
	//printf("{ link->pl = %p, link->pl->right = %lf }\n", link->pl, link->pl->right);
	if ( link->pl->right > ll.y1 )
	{
		if ( link->pl->right >= ll.y2 )
			upDatahelp(link->pl, ll);
		else
		{
			Line tmp = ll;
			tmp.y2 = link->pl->right;
			upDatahelp(link->pl, tmp);
			tmp = ll;
			tmp.y1 = link->pr->left;
			upDatahelp(link->pr, tmp);
		}
	}
	else
		upDatahelp(link->pr, ll);
	lengthhelp(link);
	//printf("{ link = %p, (link->iL = %d, link->iR = %d), (link->left = %lf, link->right = %lf), link->in = %d } \n", link, link->iL, link->iR, link->left, link->right, link->in);
}

double SegmentTree::length(){	return lengthhelp(root);	}
double SegmentTree::lengthhelp(Segment_node* link){
	link->y_len = 0;
	if ( link->in )
		link->y_len = link->right - link->left;
	else if ( NULL == link->pl && NULL != link->pr )
		link->y_len = 0 + link->pr->y_len;
	else if ( NULL != link->pl && NULL == link->pr )
		link->y_len = link->pl->y_len + 0;
	else if ( NULL != link->pl && NULL != link->pr )
		link->y_len = link->pl->y_len + link->pr->y_len;
	//printf("{ link = %p, (link->iL = %d, link->iR = %d), link->y_len = %lf, link->in = %d }\n", link, link->iL, link->iR, link->y_len, link->in);
	return link->y_len;	
}

int cmp1(const void *a, const void *b){	return ( (Line *)a )->x - ( (Line *)b )->x;	}
int cmp2(const void *a, const void *b){		return (*((double *)a)) - (*( (double *)b));	}

int main(){
	int n, testcase = 1;
	while ( 1 == scanf("%d", &n) && n )
	{
		int i;
		for ( i = 0; i < n; i ++ )
		{
			scanf("%lf%lf%lf%lf", &line[2*i].x, &line[2*i].y1, &line[2*i+1].x, &line[2*i+1].y2);
			line[2*i].y2 = line[2*i+1].y2;
			line[2*i+1].y1 = line[2*i].y1;
			line[2*i].in = 1, line[2*i+1].in = -1;
			y[2*i] = line[2*i].y1, y[2*i+1] = line[2*i].y2;
		}
		//离散化
		qsort(line, 2 * n, sizeof(line[0]), cmp1);
		qsort(y, 2 * n, sizeof(y[0]), cmp2);

		SegmentTree t(0, 2 * n - 1);
		
		double sum = 0.0;
		for ( i = 0; i < 2 * n; i ++ )
		{
			//printf("line[%d].x = %lf, line[%d].y1 = %lf, line[%d].y2 = %lf\n", i, line[i].x, i, line[i].y1, i, line[i].y2);
			t.upData(line[i]);
			sum += t.length() * ( line[i+1].x - line[i].x );
			//printf("sum = %llf\n", sum);
		}
		printf("Test case #%d\nTotal explored area: %0.2lf\n", testcase++, sum); 
	}
	return 0;
}