//

#include <iostream>
#include <math.h>
#define INF 1000001
#define MAXN 5001
using namespace std;

int val[MAXN];
int T, N;

int excet_min(int mm){
    int ret = -1, pos = 0;
    for (int i = 1; i <= N; i ++)
    {
        if (INF == val[i])  continue;
        int rr = abs(val[i] - mm);
        if (-1 == ret || ret > rr)
        {
            pos = i;
            ret = rr;
        }
    }
    //printf("[%d %d]\n", ret, pos);

    return pos;
}

int main(){
    while (EOF != scanf("%d %d", &T, &N))
    {
        int i, t, origin = 0, tt, ans = 0;
        memset(val, 0, sizeof(val));
        for (i = 1; i <= N; i ++)
            scanf("%d", &val[i]);

        t = 0;
        while (t < T)
        {
            int pos = excet_min(origin);
            if (0 == pos)   break;
            tt = abs(val[pos] - origin);

            origin = val[pos];
            val[pos] = INF;

            //printf("tt = %d\n", tt);
            if (t + tt <= T)
            {
                t += tt;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
