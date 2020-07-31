//

#define OUT(x) (cout << #x << " = " << x << endl)
#define MAXN 201
#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

int g[MAXN][MAXN], match[MAXN];
int visited[MAXN];
int n0, n1, m;

bool dfs(int p){
    int i;
    for (i = 0; i < n1; i ++)
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
    memset(match, 0xff, sizeof(int) * n1);
    int i, res = 0;
    for (i = 0; i < n0; i ++)
    {
        memset(visited, 0, sizeof(int) * n1);
        if (dfs(i)) res ++;
    }
    return res;
}

void input(){
    int i, j, sta, end;

    for (i = 0; i < n0; i++)
        for (j = 0; j < n1; j++)
            g[i][j] = 1;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &sta, &end);
        g[sta - 1][end - 1] = 0;
    }
}

int main(){
    int testcase = 1;
    while (EOF != scanf("%d %d %d", &n0, &n1, &m))
    {
        if (0 == n0 && 0 == n1 && 0 == m)   break;
        input();
        printf("Case %d: %d\n", testcase++, n0 + n1 - maxMatch());
    }
    return 0;
}


