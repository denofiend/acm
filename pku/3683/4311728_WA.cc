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

node *g[maxn], *gt[maxn], *newg[maxn];

int vis[maxn];
int id[maxn], order[maxn];
int n, m, summ, cnt, newcnt, sortcnt;

struct Time{
    int sh, sm, eh, em;
}tarray[maxn];


void dfsa(int x){
	vis[x] = 1;
	node * p1 = gt[x];
	while (NULL != p1)
	{
		if (!vis[p1->to])
			dfsa(p1->to);
		p1=p1->next;
	}
	order[cnt++] = x;
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


void input(){
    int h, m, h1, m1, Di, s0, s1;

    REP (i, n)
    {
        scanf("%d:%d %d:%d %d", &h, &m, &h1, &m1, &Di);

        tarray[2*i].sh = h;
        tarray[2*i].sm = m;

        s0 = (h * 60 + m + Di);

        tarray[2*i].eh = s0 / 60;
        tarray[2*i].em = s0 % 60;

        tarray[2*i+1].eh = h1;
        tarray[2*i+1].em = m1;
        s1 = (h1 *60 + m1 - Di);

        tarray[2*i+1].sh = s1 / 60;
        tarray[2*i+1].sm = s1 % 60;
    }

//    REP (i, n)
//    {
//        printf("%02d:%02d %02d:%02d\t %02d:%02d %02d:%02d\n", tarray[2*i].sh, tarray[2*i].sm, tarray[2*i].eh, tarray[2*i].em, tarray[2*i+1].sh, tarray[2*i+1].sm, tarray[2*i+1].eh, tarray[2*i+1].em);
//    }
}

int startTime(int i){
    return tarray[i].sh * 60 + tarray[i].sm;
}
int endTime(int i){
    return tarray[i].eh * 60 + tarray[i].em;
}

void insertnew(int from, int to){
    tp[newcnt].to = to;
    tp[newcnt].next = newg[from];
    newg[from] = (&tp[newcnt++]);
}


void dfsb(int i){
    vis[i] = 1;

    node *p = newg[i];
    while (NULL != p)
    {
        if (!vis[p->to])    dfsb(p->to);
        p = p->next;
    }
    order[sortcnt++] = i;
}

bool ok(int i, int j){
    return (startTime(i) <= startTime(j) && startTime(j) <= endTime(i) ||
                startTime(j) <= startTime(i) && startTime(i) <= endTime(j));
}

void dfsc(int i){
    vis[i] = 2;
    node *p = newg[i];
    while (NULL != p)
    {
        if (!vis[p->to])    dfsc(p->to);
        p = p->next;
    }
}


void output(node **g){
    REP (i, n+n)
    {
        printf("%d-> ", i);
        node *p = g[i];
        while (NULL != p)
        {
            printf("%d ", p->to);
            p = p->next;
        }
        printf("\n");
    }
}
void twoSat(){
    summ = 0;
    for (int i = 0; i < n+n; i ++)
    {
        for (int j = i+1; j < n+n; j ++)
        {
            if (i == (j ^ 1)) continue;
            if (ok(i, j))
            {
                //printf("[%d %d]\n", i, j);
                insert(i, j^1);
                insert(j, i^1);
            }
        }
    }

    if (!test())
    {
        printf("NO\n");
        return;
    }
    //output(g);
    // 缩点, 拓扑排序, 构造解

    newcnt = 0;
    REP (i, n+n)
    {
        node *p = gt[i];
        while (NULL != p)
        {
            if (id[i] != id[p->to])
            {
                insertnew(id[i], id[p->to]);
            }
            p = p->next;
        }
    }
    REP (i, n)
    {
        int a = id[2*i];
        int b = id[2*i+1];
        node *p;
        for (p = newg[a]; NULL != p; p = p->next)   if (p->to == b) break;
        if (NULL == p)
        {
            insertnew(a, b);
            //insertnew(b, a);
        }
    }
    //output(newg);
    memset(order, 0, sizeof(order));
    memset(vis, 0, sizeof(vis));

    sortcnt = 0;
    FORD (i, cnt-1, 0)
    {
        if (!vis[i])    dfsb(i);
    }

    memset(vis, 0, sizeof(vis));
    FORD (i, cnt-1, 0)
    {
        if (!vis[order[i]])
        {
            vis[order[i]] = 1;
            for (node *p = newg[order[i]]; NULL != p; p = p->next)
                dfsc(i);
        }
    }

    printf("YES\n");
    for (int i = 0; i < n+n; i += 2)
    {
        if (1 == vis[id[i]])    printf("%02d:%02d %02d:%02d\n", tarray[i].sh, tarray[i].sm, tarray[i].eh, tarray[i].em);
        else printf("%02d:%02d %02d:%02d\n", tarray[i+1].sh, tarray[i+1].sm, tarray[i+1].eh, tarray[i+1].em);
    }
}


int main(){
    while (EOF != scanf("%d\n", &n))
    {
        input();
        twoSat();
    }
	return 0;
}

