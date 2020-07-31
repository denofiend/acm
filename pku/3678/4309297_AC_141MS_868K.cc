//
// 2-sat
//
//

#include <iostream>
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; ++i) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; ++i) out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for (int i = (int)a; i >= (int)b; --i)


#include<stdio.h>
#include<string.h>
#define maxn 2020
#define maxm maxn*maxn

struct node{
	int to;
	node * next;
}tp[maxm+maxm];

node *g[maxn], *gt[maxn];


int vis[maxn];
int id[maxn], order[maxn];
int n, m, summ, cnt;

void dfsa(int x){
	vis[x] = 1;
	node * p1 = gt[x];
	while (NULL != p1)
	{
		if (!vis[p1->to])
			dfsa(p1->to);
		p1=p1->next;
	}
	order[cnt++]=x;
}

void dfs(int x){
	vis[x] = 1;
	id[x] = cnt;
	node *p1 = g[x];
	while (NULL != p1)
	{
	    if (!vis[p1->to])
	    {
	        dfs(p1->to);
	    }
	    p1 = p1->next;
	}
}

bool test(){
	memset(vis, 0, sizeof(vis));
	cnt = 0;
	REP (i, n+n)
	{
	    if (!vis[i])    dfsa(i);
	}

	memset(vis, 0, sizeof(vis));

    cnt = 0;
    FORD (i, n+n-1, 0)
    {
        if (!vis[order[i]])
        {
            dfs(order[i]);
            cnt++;
        }
    }

    REP (i, n)
    {
        if (id[i+i] == id[i+i+1])  return false;
    }
    return true;

}

void insert(int from, int to){
    tp[summ].to = to;
    tp[summ].next = g[from];
    g[from] = &(tp[summ++]);

    tp[summ].to = from;
    tp[summ].next = gt[to];
    gt[to] = &(tp[summ++]);
}

int main(){
	char temp[5];
	int from, to, ans1;
	scanf("%d%d", &n, &m);
	summ = 0;
	while (m--)
	{
	    scanf("%d%d%d%s", &from, &to, &ans1, temp);

		if ('A' == temp[0])
		{
			if (ans1)
			{
			    insert(from+from, from+from+1);
			    insert(to+to, to+to+1);
			    //insert(from+from+1, to+to+1);
			    //insert(to+to+1, from+from+1);
			}
			else
			{
			    insert(from+from+1, to+to);
			    insert(to+to+1, from+from);
            }
		}
		else if ('O' == temp[0])
		{
			if (ans1)
			{
			    insert(from+from, to+to+1);
			    insert(to+to, from+from+1);
			}
			else
			{
			    insert(from+from+1, from+from);
			    insert(to+to+1, to+to);

			    //insert(from+from, to+to);
			    //insert(to+to, from+from);
            }
		}
		else
		{
			if (ans1)
			{
			    insert(from+from, to+to+1);
			    insert(to+to+1, from+from);

			    insert(from+from+1, to+to);
			    insert(to+to, from+from+1);
			}
			else
			{
			    insert(from+from, to+to);
			    insert(to+to, from+from);

			    insert(from+from+1, to+to+1);
			    insert(to+to+1, from+from+1);
            }
		}
	}

	if (test()) puts("YES");
	else puts("NO");
	return 0;
}

