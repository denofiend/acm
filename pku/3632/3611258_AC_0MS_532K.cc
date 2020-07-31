
#include <iostream>
#include <math.h>
#define MAXN 200
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i++) cout << x[i] << " ";    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out(x[i], m);   cout << endl;   }


int n;

int g[MAXN][MAXN];
int pos[MAXN];
int visited[MAXN];

int cmp(const void *a, const void *b){
    return (*(int *)a) - (*(int *)b);
}




int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(g, 0, sizeof(g));
        scanf("%d", &n);
        int min = MAXN, max = -1;
        for (int i = 0; i < n; i ++)
        {
            scanf("%d", &pos[i]);

            if (min > pos[i])   min = pos[i];
            if (max < pos[i])   max = pos[i];
        }
        qsort(pos, n, sizeof(pos[0]), cmp);


        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (i == j) continue;
                g[i][j] = abs(pos[i] - pos[j]);
            }
        }

        int ans = 0xffffff;
        int start, end;
        for (int i = 0; i < n; i ++)
        {
            int sum = 0;
            start = i;
            end = i - 1;
            while (end >= 0)
            {
                sum += g[start][end];
                start = end;
                end --;
            }
            sum += g[start][i];

            end = i + 1;
            while (end < n)
            {
                sum += g[start][end];
                start = end;
                end ++;
            }
            sum += g[start][i];

            if (ans > sum)  ans = sum;

        }
        printf("%d\n", ans);
    }
    return 0;
}
