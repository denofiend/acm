//
//

#include <iostream>
#define MAXN 1000001
#define Inf 50001
using namespace std;


struct Node{
	int left, mid, right, cnt1, cnt2;
};

Node nd[MAXN];
int n, m, maxn;

void creat(int root, int ll, int rr){
	if (root > maxn)	maxn = root;

	int mid = (ll + rr) >> 1;



	nd[root].left = ll;

	nd[root].mid = mid;

	nd[root].right = rr;

	nd[root].cnt1 = rr - ll + 1, nd[root].cnt2 = 0;



	if (nd[root].left == nd[root].right)   return;



	if (nd[root].left < nd[root].right)

	{

		creat(root * 2, ll, mid);

		creat(root * 2 + 1, mid + 1, rr);

	}

}

int insert(int root, int &cnt){
	//printf("[%d %d]\n", root, cnt);
	if (nd[1].cnt1 < cnt || 0 == cnt || 0 == nd[root].cnt1 || root > maxn)	return Inf;
	if (nd[root].left == nd[root].right)
	{
		if (1 == nd[root].cnt1 && 0 == nd[root].cnt2)
		{
			nd[root].cnt1 = 0;
			nd[root].cnt2 = 1;
			cnt --;
			return nd[root].left;
		}
		return Inf;
	}
	int ll = Inf, rr = Inf;
	if (nd[root].mid >= nd[root].left && nd[root * 2].cnt1)
		ll = insert(root * 2, cnt);
	if (nd[root].right >= nd[root].mid && nd[root * 2 + 1].cnt1)
		rr = insert(root * 2 + 1, cnt);

	if (root * 2 + 1 <= maxn)
	{
		nd[root].cnt1 = nd[root * 2].cnt1 + nd[root * 2 + 1].cnt1;
		nd[root].cnt2 = nd[root * 2].cnt2 + nd[root * 2 + 1].cnt2;
	}
	//printf("nd[%d].cnt1 = %d, nd[%d].cnt2 = %d\n", root, nd[root].cnt1, root, nd[root].cnt2);
	return min(ll, rr);
}

void deleteTree(int root, const int pos, int &cnt){
	if (0 == cnt || pos > nd[root].right || root > maxn)	return;
	//printf("<%d %d %d>\n", root, pos, cnt);
	if (nd[root].left == nd[root].right)
	{
		//printf("[%d %d %d %d]\n", nd[root].left, nd[root].right, nd[root].cnt1, nd[root].cnt2);
		if (nd[root].left >= pos && 0 == nd[root].cnt1 && 1 == nd[root].cnt2)	
		{
			nd[root].cnt1 = 1;
			nd[root].cnt2 = 0;
			cnt --;
		}
		return;
	}

	if (nd[root].mid >= pos && cnt)
	{
		deleteTree(root * 2, pos, cnt);
	}

	if (nd[root].right >= pos && cnt)
	{
		deleteTree(root * 2 + 1, pos, cnt);
	}

	if (root * 2 + 1 <= maxn)
	{
		nd[root].cnt1 = nd[root * 2].cnt1 + nd[root * 2 + 1].cnt1;
		nd[root].cnt2 = nd[root * 2].cnt2 + nd[root * 2 + 1].cnt2; 
	}
	//printf("nd[%d].cnt1 = %d, nd[%d].cnt2 = %d\n", root, nd[root].cnt1, root, nd[root].cnt2);
}

int main(){
	int i, check, a, b;
	scanf("%d %d", &n, &m);
	maxn = 0;
	creat(1, 1, n);

	//printf("maxn = %d\n", maxn);
	for (i = 0; i < m; i ++)
	{
		scanf("%d", &check);
		if (1 == check)
		{
			scanf("%d", &a);
			//printf("<%d %d>\n", check, a);
			int flag = insert(1, a);
			if (Inf == flag)	printf("0\n");
			else printf("%d\n", flag);
		}
		else if (2 == check)
		{
			scanf("%d %d", &a, &b);	
			//printf("<%d %d %d>\n", check, a, b);
			deleteTree(1, a, b);
		}
	}
	return 0;
}