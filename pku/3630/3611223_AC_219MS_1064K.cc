//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[10000][11];

int cmp(const void *a, const void *b){
    char *aa = (char *)a;
    char *bb = (char *)b;
    return strcmp(aa, bb);
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++)    scanf("%s", str[i]);

        qsort(str, n, sizeof(str[0]), cmp);
        int flag = 1;
        for (int i = 0; i < n - 1 && flag; i ++)
        {
            int k;
            for (k = 0; k < strlen(str[i]); k++)
                if (str[i][k] != str[i + 1][k])
                {
                    break;
                }

            if (k == strlen(str[i]))    flag = 0;
        }
        if (flag)   printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
