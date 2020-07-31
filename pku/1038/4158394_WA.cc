// 1038
//
// dp

#define OUT(x) (cout << #x << ": " << x << endl)
#define MAXN 60000
#include <iostream>
using namespace std;
typedef long long int64;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i++) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; i++)  out(x[i], m);   cout << endl;   }


int g[150][10], blk[10];
int f[4][MAXN];
int e[11] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int n, m, kn;
int can1, can2, bite[10][MAXN];


void init(){
    int i, j, tmp;
    for (i = 0; i < e[10]; i++)
    {
        j = 0;
        tmp = i;
        while (tmp > 0)
        {
            bite[j][i] = tmp % 3;
            tmp /= 3;
            j++;
        }
    }
}

void input(){
    int i, x, y;
    scanf("%d %d %d", &n, &m, &kn);
    //printf("[%d %d %d]\n", n, m, kn);
    memset(g, 0, sizeof(g));
    for (i = 0; i < kn; i++)
    {
        scanf("%d %d", &x, &y);
        g[x-1][y-1] = 1;
    }
    //out(g, n, m);
}

void dp(){
    int i, j, k, c, a1, a2;
    memset(f, 0, sizeof(f));
    for (i = 0; i < m; i++) blk[i] = 1 - g[0][i];
    //out(blk, m);

    c = 2;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (g[i][j]) blk[j] = 0;
            else blk[j]++;

            c = (c + 1) % 4;
            can1 = ((j > 0) && (blk[j-1] > 2) && (blk[j] > 2));
            can2 = ((j > 1) && (blk[j-1] > 1) && (blk[j] > 1) && (blk[j - 2] > 1));


            a1 = 2 * e[j] + 2 * e[j-1];

            a2 = e[j] + e[j-1] + e[j-2];

            for (k = 0; k < e[m]; k++)
            {
                if (bite[j][k])
                {
                    f[c][k] = f[(c + 3) % 4][k - e[j]];
                }
                else
                {
                    f[c][k] = f[(c + 3) % 4][k];
                    if (j > 0 && !bite[j-1][k])
                    {

                        if (can1)   f[c][k] = max(f[c][k], f[(c + 2) % 4][k + a1] + 1);
                        if (can2 && j > 1 && !bite[j-2][k])  f[c][k] = max(f[c][j], f[(c + 1) % 4][k + a2] + 1);
                    }
                }
            }
        }
    }
    printf("%d\n", f[c][0]);
}


int main() {
    int testcase;
    init();
    scanf("%d", &testcase);
    while (testcase--)
    {
        input();
        dp();
    }
    return 0;
}
