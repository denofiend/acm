// 1321(pku)


#include <iostream>

using namespace std;


template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

int n, k;
int MAX;
char maze[10][10];
int visitedX[10], visitedY[10];

void input(){
    memset(maze, 0xff, sizeof(maze));

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            scanf("%c", &maze[i][j]);
        }
        scanf("\n");
    }
    MAX = n * n;
    #ifdef DEBUG
        out(maze, n, n);
    #endif
}

int dfs(int pos, int num){
    if (num == k)
    {
        #ifdef DEBUG
            printf("<%d %d %d %d>\n", pos / n, pos % n, num, k);
        #endif
        return 1;
    }
    if (pos >= MAX) return 0;
    while ('#' != maze[pos / n][pos % n] && pos < MAX)
    {
        pos++;
    }

    #ifdef DEBUG
        printf("[%d %d %d]\n", pos / n, pos % n, num);
    #endif
    if (pos >= MAX) return 0;
    int ans = 0;
    int x = pos / n, y = pos % n;

    if (0 == visitedX[x] && 0 == visitedY[y])
    {
        visitedX[x] = 1;
        visitedY[y] = 1;
        ans += dfs(pos + 1, num + 1);
        visitedX[x] = 0;
        visitedY[y] = 0;
    }
    ans += dfs(pos + 1, num);
    
    return ans;
}
void solve(){
    int cnt = 0;
    memset(visitedX, 0, sizeof(visitedX));
    memset(visitedY, 0, sizeof(visitedY));

    cnt = dfs(0, 0);

    printf("%d\n", cnt);
}

int main(){
    while (2 == scanf("%d %d\n", &n, &k))
    {
        if (-1 == n && - 1== k) break;
        input();
        solve();
    }
    return 0;
}
