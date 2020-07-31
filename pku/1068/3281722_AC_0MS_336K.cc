// 1068(pku)

#include <stdio.h>
#include <string.h>
#define MAXN 10000

char par[MAXN];
int matched[MAXN];

int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int i, j = 0;
        int lefn, num = 1;
        for (i = 0; i < n; i ++)
        {
            scanf("%d", &lefn);
            while (num <= lefn)
            {
                par[j++] = '(';
                num++;
            }
            par[j++] = ')';
        }
        par[j] = '\0';
        int len = strlen(par);
        memset(matched, 0, sizeof(matched));
        for (i = 0, num = 0, j = 0; i < len; i ++)
        {
            if (')' == par[i])
            {
                for (j = i - 1, num = 0; j >= 0; j --)
                {
                    if ('(' == par[j])
                    {
                        num++;
                        if (!matched[j])
                        {
                            matched[j] = 1;
                            break;
                        }
                    }
                }
                printf("%d ", num);
            }
        }
        printf("\n");

    }
    return 0;
}
