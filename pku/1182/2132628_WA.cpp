#include <iostream>
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
Node* s;
void MakeSet(Node & x){
	x.parent = &x;
	x.relat = 0;
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
Node & FindSet(Node & x){ 
	s = x.parent;
	if(s != &x)
	{
		x.relat = (x.relat + x.parent->relat) % 3;
		s->parent = &(FindSet(*(s->parent)));
	}
	return *s;
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
		Node & rx = FindSet(v[p]);
		Node & ry = FindSet(v[son]);	
		if(rx != ry)
		{
			ry.relat = (v[p].relat + r + 2 - v[son].relat) % 3;
			Link(ry,rx);	
		}
		else
		{
			if((v[son].relat - v[p].relat + 3 ) % 3 != r - 1)
			{
				wrong ++;
			}
		}
	
	}
	cout << wrong;
	return 0;
}