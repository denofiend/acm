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
    scanf("%d\n", &n);
    //if (n < 0) n = -n;
    int i = n;
    char c;
    while (i --)
    {
        scanf("%c", &c);
        if ('p' == c)    flag[i] = 1;
        else if ('n' == c)  flag[i] = -1;
    }
    scanf("%I64d", &m);
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
    if (m)  printf("Impossible\n");
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
