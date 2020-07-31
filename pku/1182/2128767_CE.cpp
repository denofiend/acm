//1182 食物链

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int relat;
	int rank;            //秩
	Node* parent;
};
int n;
int ns;
int wrong;
void MakeSet(Node & x){
	x.parent = &x;
	x.rank = 0;
}
void Link(Node & x,Node & y){
	if(x.rank > y.rank)
		y.parent = &x;
	else
	{
		x.parent = &y;
		if(x.rank == y.rank)
			y.rank ++;
	}
}
Node FindSet(Node & x){
	if(x.parent != &x)
		x.parent = &FindSet(*(x.parent));
	x.parent->relat = x.relat;
	return *(x.parent);
}
void Union(Node & x,Node & y){
	Node rx = FindSet(x);
	Node ry = FindSet(y);
	if(&rx == &ry)
	{
		if(ry.relat != y.relat)
			wrong ++;
		else
			Link(rx,ry);
	}
	Link(rx,ry);
}


int main(){
	cin >> n >> ns;
	Node* v = new Node [n + 1];
	for(int j = 1;j <= n;j ++)
		MakeSet(v[j]);
	for(int i = 1;i <= ns;i ++)
	{
		int r,p,son;
		cin >> r >> p >> son;

		if(p > n || son > n)
		{
			wrong ++;
			continue;
		}
		if(r == 2 && p == son)
		{
			wrong ++;
			continue;
		}
		v[p].relat = r;		
		Union(v[son],v[p]);
	}
	cout << wrong;
	return 0;


}