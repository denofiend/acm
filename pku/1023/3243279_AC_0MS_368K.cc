// 1023(pku)
// DenoFiend


#include <iostream>
#define MAXN 65
using namespace std;

int  n;
__int64 m;
int flag[MAXN];
char ans[MAXN];
int cnt;
void input(){
    memset(flag, 0, sizeof(flag));
    memset(ans, 0, sizeof(ans));
    scanf("%d\n", &n);
    //if (n < 0) n = -n;
    int i;
    char c;
    for (i = n - 1; i >= 0; i --)
    {
        scanf("%c", &c);
        if ('p' == c)    flag[i] = 1;
        else if ('n' == c)  flag[i] = -1;
    }
    scanf("%I64d", &m);
    //if (m < 0)
    //{
    //    //for (i = 0; i
    //}
}

void solve(){
    int i, j = n - 1;
    for (i = 0; i < n; i ++)
    {
        if (m % 2)
        {
            m = (m - flag[i]) / 2;
            ans[j --] = '1';
        }
        else
        {
            m /= 2;
            ans[j --] = '0';
        }
    }
    if (0 != m)  printf("Impossible\n");
    else printf("%s\n", ans);
}
int main(){
    int t;
    scanf("%d\n", &t);
    while (t --)
    {
        input();
        solve();
    }
    return 0;
}
