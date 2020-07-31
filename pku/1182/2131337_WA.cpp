#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int relat;
	int rank;
	Node * parent;
	bool operator == (const Node & x){
		return(this->parent == x.parent && this->rank == x.rank && this->relat == x.relat);
	}
	bool operator != (const Node &x){
		return(this->parent != x.parent ||this->rank != x.rank || this->relat != x.relat);
	}
};
int wrong;
void MakeSet(Node & x){
	x.parent = &x;
	x.rank = 0;
}
void Link(Node & x,Node & y){
	if (x.rank > y.rank)
		y.parent = &x;
	else
	{
		x.parent = &y;
		if(x.rank == y.rank)
			y.rank ++;
	}
}
Node & FindSet(Node &x){
	if(*(x.parent) != x)
	{
		x.parent->relat = x.relat;
		x.parent = &(FindSet(*(x.parent)));
	}
	return *(x.parent);
}
void Union(Node & x,Node & y){
	Node& ry = FindSet(y);
	int tem = ry.relat;
	Node& rx = FindSet(x);
	if(rx == ry)
	{
		if(tem != rx.relat)	
		{
			wrong ++;
			return;
		}
	}
	Link(rx,ry);
}
int main(){
	int n,ns;
	cin >> n >> ns;
	Node * v = new Node[n + 1];
	for(int i = 1;i <= n;i ++)
		MakeSet(v[i]);
	for(int j = 1;j <= ns;j ++)
	{
		int r,p,son;
		cin >> r >> p >> son;
		if(p > n || son > n)
		{
			wrong ++;
			continue;
		}
		if(r ==2 && p == son)
		{
			wrong ++;
			continue;
		}
		v[son].relat = r;
		Union(v[son],v[p]);
	}
	cout << wrong;
	return 0;
}