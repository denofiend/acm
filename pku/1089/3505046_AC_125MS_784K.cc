//

#include <iostream>
#include <algorithm>
#define MAXN 500001
using namespace std;


struct Node{
    int ai, bi;
};

Node nd[MAXN];

bool cmp(const Node &a, const Node &b){
    return a.ai < b.ai;
}


int main(){
    int n;
    while (1 == scanf("%d", &n))
    {
        for (int i = 0; i < n; i ++)
            scanf("%d %d", &nd[i].ai, &nd[i].bi);
        sort(nd, nd + n, cmp);

        int pos = 0;
        for (int i = 1; i < n; i ++)
        {
            if (nd[pos].bi >= nd[i].ai)
            {
                nd[pos].bi = max(nd[pos].bi, nd[i].bi);
            }
            else
            {
                printf("%d %d\n", nd[pos].ai, nd[pos].bi);
                pos = i;
            }
        }
        printf("%d %d\n", nd[pos].ai, nd[pos].bi);
    }
    return 0;
}
