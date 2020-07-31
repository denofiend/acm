// 1274(pku)


#include <iostream>
#define MAXN 201
using namespace std;



template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++) cout << x[i] << " "; cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++) out(x[i], m);  cout << endl;	}
int g[MAXN][MAXN], match[MAXN];
int visited[MAXN];
int n, m;

void input(){
    memset(g, 0, sizeof(g));
    int i, to;
    int mm;
    for (i = 0; i < n; i ++)
    {
        scanf("%d", &mm);
        while (mm --)
        {
            scanf("%d", &to);
            if (0 == g[i][to - 1])
                g[i][to - 1] = 1;
        }
    }
   // out(g, n, m);
}

bool dfs(int p){
    int i;
    for (i = 0; i < m; i ++)
    {
        if (g[p][i] && !visited[i])
        {
            visited[i] = 1;

            int t = match[i];

            match[i] = p;
            if (-1 == t || dfs(t))
                return true;
            match[i] = t;
        }
    }
    return false;
}
int maxMatch(){
    memset(match, 0xff, sizeof(int) * m);
    int i, res = 0;
    for (i = 0; i < n; i ++)
    {
        memset(visited, 0, sizeof(int) * m);
        if (dfs(i)) res ++;
    }
    return res;
}
void solve(){
    printf("%d\n", maxMatch());
}
int main(){
    while (2 == scanf("%d%d", &n, &m))
    {
        input();
        solve();
    }
    return 0;
}
