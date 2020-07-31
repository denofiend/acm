// 3683(pku)
// 2-sat

#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; ++i) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; ++i) out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i,a, b)    for (int i = (int)a; i >= (int)b; --i)
#define MAXN 1100
#define MAXX 8000000
#define l(A) (A<<1)
#define r(B) (B<<1)+1

struct edge{
	int v;
	edge* next;
}pool[MAXX], *adj[MAXN+MAXN], *ddj[MAXN+MAXN], *newadj[MAXN+MAXN], *pp = pool;

int sc[MAXN+MAXN];
int n, s[MAXN], t[MAXN], d[MAXN];

inline void insert(int s, int t){
    pp->v = t;
    pp->next = adj[s];
    adj[s] = pp++;

    pp->v = s;
    pp->next = ddj[t];
    ddj[t]=pp++;
}
inline void insertn(int s, int t){
    pp->v = t;
    pp->next = newadj[s];
    adj[s] = pp++;
}

int pos[2100],tim=0,color[2100];
bool vis[2100];

void dfs1(int i){
    vis[i] = true;
    for (edge *p = ddj[i]; p; p = p->next)
    {
        if (!vis[p->v]) dfs1(p->v);
    }
    pos[tim++] = i;
}

void dfs2(int i, int id){
    vis[i] = false;
    sc[i] = id;
    for (edge *p = adj[i]; p; p = p->next)
    {
        if (vis[p->v])  dfs2(p->v, id);
    }
}

void dfs(int i){
    vis[i] = true;
    for (edge *p = newadj[i]; p; p = p->next)
    {
        if (!vis[p->v]) dfs(p->v);
    }
    pos[tim++] = i;
}

void out(int x){
    printf("%02d:%02d", x / 60, x % 60);
}


void output(edge **g){
    for (int i = 0; i < n+n; ++i)
    {
        edge *p = g[i];
        printf("%d->", i);
        while (NULL != p)
        {
            printf(" %d", p->v);
            p = p->next;
        }
        printf("\n");
    }
}


bool sat(){
    memset(vis, 0, sizeof(vis));
    tim = 0;
    int i;
    for (i = 0; i < (n << 1); ++i)
    {
        if (!vis[i])    dfs1(i);
    }
    for (i = pos[--tim]; tim >= 0; i = pos[--tim])
    {
        if (vis[i]) dfs2(i, i);
    }
    //out(sc, n+n);

    for (i = 0; i < (n << 1); i += 2)
    {
        if (sc[i] == sc[i+1])
        {
            printf("NO\n");
            return false;
        }
    }

    printf("YES\n");

    //output(adj);
    //printf("\n");
    for (i = 0; i < (n << 1); ++i)
    {
        if (sc[i] != i)
        {
            for (edge *p = adj[i]; p; p = p->next)
            {
                insertn(sc[p->v], sc[i]);
            }
        }
    }

    //output(adj);

    // 盖时间戳(拓扑排序)
    tim = 0;
    for (i = 0; i < (n << 1); ++i)
    {
        if (sc[i] == i)
        {
            dfs(i);
        }
    }
    //out(pos, tim);
    memset(color, 0, sizeof(color));

    int ttim = 0;
    for (i = pos[ttim++]; ttim < tim; i = pos[ttim++])
    {
        if (!color[i])
        {
            color[sc[i]] = 1;
            color[sc[i^1]] = 2;
        }
    }

    //test();
    for (i = 0; i < n; ++i)
    {
        if (1 == color[sc[l(i)]])
        {
            out(s[i]);
            printf(" ");
            out(s[i]+d[i]);
            printf("\n");
        }
        else
        {
            out(t[i]-d[i]);
            printf(" ");
            out(t[i]);
            printf("\n");
        }
    }

    return true;
}

int get(char * a){
    return ((a[0]&0xf)*10+(a[1]&0xf))*60+(a[3]&0xf)*10+(a[4]&0xf);
}


int main(){
    char ss[10], tt[10];
    int s1, s2, t1, t2;
    scanf("%d", &n);
    REP (i, n)
    {
        scanf("%s%s%d", ss, tt, &d[i]);
        s[i] = get(ss);
        t[i] = get(tt);
    }

//    REP (i, n)
//    {
//        out(s[i]);
//        printf(" ");
//        out(s[i]+d[i]);
//        printf("\t");
//        out(t[i]-d[i]);
//        printf(" ");
//        out(t[i]);
//        printf("\n");
//    }

    //　建图
    REP (i, n)
    {
        REP (j, n)
        {
            if (i == j)continue;

            s1 = s[i], t1 = s[i] + d[i];
            s2 = s[j], t2 = s[j] + d[j];

            if (s1 < t2 && s2 < t1)
            {
                insert(l(i), r(j));
            }

            s2 = t[j] - d[j], t2 = t[j];

            if (s1 < t2 && s2 < t1)
            {
                insert(l(i), l(j));
            }

            s1 = t[i] - d[i], t1 = t[i];
            s2 = s[j], t2 = s[j] + d[j];

            if (s1 < t2 && s2 < t1)
            {
                insert(r(i), r(j));
            }

            s2 = t[j] - d[j], t2 = t[j];

            if (s1 < t2 && s2 < t1)
            {
                insert(r(i), l(j));
            }

        }
    }
    //output(ddj);
    //printf("\n");
    //output(adj);
    sat();
    return 0;
}

