//


#include <iostream>
#include <algorithm>
#define MAXN 220
#define MAXX 22000
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

struct Point{
    int x, y;
};

struct Line{
    int ax, by;
};

Point pt[MAXN];
Line ln[MAXX];

bool cmp(const Line &a, const Line &b){
    return a.by * b.ax < a.ax * b.by;
}

int main(){
    int n;
    while (EOF != scanf("%d", &n))
    {
        int i, j, ans, m;
        for (i = 0; i < n;  i++)    scanf("%d %d", &pt[i].x, &pt[i].y);

        m = 0;
        for (i = 0; i < n; i ++)
            for (j = i + 1; j < n; j ++)
            {
                int ax = pt[i].x - pt[j].x;
                int by = pt[i].y - pt[j].y;

                if (0 == ax)    by = 1;
                if (0 > ax)
                {
                    ax = -ax;
                    by = -by;
                }
                ln[m].ax = ax;
                ln[m++].by = by;
            }
        sort(ln, ln + m, cmp);

        ans = 1;

        //for (i = 0; i < m; i ++)
        //   printf("[%d %d]\n", ln[i].ax, ln[i].by);
        for (i = 1; i < m; i ++)
            if (ln[i].by * ln[i - 1].ax != ln[i].ax * ln[i - 1].by)
                ans ++;
        printf("%d\n", ans);
    }
    return 0;
}
