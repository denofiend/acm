//

#include <iostream>
#include <algorithm>
#define MAXN 50001
using namespace std;

struct Node{
    int ai, bi;
};

Node nd[MAXN];
bool cmp(const Node &a, const Node &b){
    if (a.ai == b.ai)
    {
        return a.bi < b.bi;
    }
    else
    {
        return a.ai < b.ai;
    }
}

int main(){
    freopen("a.in", "r", stdin);
    int n;
    while (1 == scanf("%d", &n))
    {
        for (int i = 0; i < n; i ++)
            scanf("%d %d", &nd[i].ai, &nd[i].bi);

        sort(nd, nd + n, cmp);
        printf("%d ", nd[0].ai);
        for (int i = 1; i < n; i ++)
        {
            if (nd[i].ai > nd[i - 1].bi)
            {
                printf("%d\n%d ", nd[i - 1].bi, nd[i].ai);
            }
        }
        printf("%d\n", nd[n - 1].bi);
    }
    return 0;
}
