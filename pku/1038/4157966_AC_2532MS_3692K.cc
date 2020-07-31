// 1038
//
// dp

#define OUT(x) (cout << #x << ": " << x << endl)
#include <iostream>
using namespace std;
typedef long long int64;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i++) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; i++)  out(x[i], m);   cout << endl;   }


int g[150][10], blk[10];
int d[4][60000];
int e[11] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int n, m, kn;
int can1, can2, b[10][60000];
int *l0, *l1, *l2, *l3, *bit0, *bit1, *bit2;

void build() {
    int i, j, tmp;
    for (i = 0; i < e[10]; i++)
    {
        j = 0;
        tmp = i;
        while (tmp > 0)
        {
            b[j][i] = tmp % 3;
            tmp /= 3;
            j++;
        }
    }
}

inline int maxt(int a, int b) {
    return a > b ? a : b;
}

void solve() {
    int i, j, x, y, a1, a2, p, c;
    scanf("%d%d%d", &n, &m, &kn);
    memset(g, 0, sizeof(g));
    memset(d, 0, sizeof(d));

    for (i = 0; i < kn; i++)
    {
        scanf("%d%d", &x, &y);
        g[x-1][y-1] = 1;
    }
    for (i = 0; i < m; i++) blk[i] = 1 - g[0][i];

    for (i = 1, c = 2; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (g[i][j]) blk[j] = 0;
            else blk[j]++;

            c = (c + 1) % 4;

            can1 = (j > 0 && blk[j] > 2 && blk[j-1] > 2);
            can2 = (j > 1 && blk[j] > 1 && blk[j-1] > 1 && blk[j-2] > 1);

            a1 = 2*e[j]+2*e[j-1];
            a2 = e[j]+e[j-1]+e[j-2];

            l0 = d[c]; l1 = d[(c+3)%4]; l2 = d[(c+2)%4]; l3 = d[(c+1)%4];
            bit0 = b[j];

            if (j>0) bit1 = b[j-1];
            if (j>1) bit2 = b[j-2];

            for (p = 0; p < e[m]; p++)
            {
                if (bit0[p])
                {
                    l0[p] = l1[p-e[j]];
                } else
                {
                    l0[p] = l1[p];
                    if (j > 0 && !bit1[p])
                    {
                        if (can1) l0[p] = maxt(l0[p], l2[p+a1] + 1);
                        if (can2 && !bit2[p]) l0[p] = maxt(l0[p], l3[p+a2]+1);
                    }
                }
            }
        }
    }
    printf("%d\n", d[c][0]);
}

int main() {
    build();
    int caseTime;
    scanf("%d", &caseTime);
    while (caseTime--)
    {
        solve();
    }
    return 0;
}
