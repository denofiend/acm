//

#include <iostream>
#include <algorithm>
#define MAXN 50001
using namespace std;


struct Node{
	int ai, bi;
	int id;
};
Node nd[MAXN];

bool cmp1(const Node a, const Node b){
	return a.ai > b.ai;
}
bool cmp2(const Node a, const Node b){
	return a.bi > b. bi;
}

int main(){
	int n, k;
	while (EOF != scanf("%d %d", &n, &k))
	{
		for (int i = 0; i < n; i ++)
		{
			scanf("%d %d\n", &nd[i].ai, &nd[i].bi);
			nd[i].id = i + 1;
		}
		sort(nd, nd + n, cmp1);
		sort(nd, nd + k, cmp2);
		printf("%d\n", nd[0].id);
	}
	return 0;
}