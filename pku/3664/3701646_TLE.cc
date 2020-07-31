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
	while (cin >> n >> k)
	{
		for (int i = 0; i < n; i ++)
		{
			cin >> nd[i].ai >> nd[i].bi;
			nd[i].id = i + 1;
		}
		sort(nd, nd + n, cmp1);
		sort(nd, nd + k, cmp2);
		cout << nd[0].id << endl;
	}
	return 0;
}