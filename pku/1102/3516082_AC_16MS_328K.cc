//

#include <iostream>
#define MAXN 1000
using namespace std;

char ans[MAXN][MAXN];

int table[10][7] = { {1, 1, 1, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1}, {0, 1, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

int main(){
    //freopen("a.in", "r", stdin);
    int p;
    char digit[MAXN];
    while (2 == scanf("%d %s", &p, digit))
    {
        int len = strlen(digit);
        if (0 == p && 0 == digit)   break;

        for (int i = 0; i <= 2 * p + 2; i ++)
        {
           // printf(" ");
            for (int j = 0; j <= (len - 1) *(p + 3) + p + 2; j ++)
            {
                ans[i][j] = ' ';
            }
        }
        for (int i = 0; i < 7; i ++)
        {
            for (int j = 0; j < len; j ++)
            {
                if (1 == table[ digit[j] - '0' ][i])
                {

                    if (0 == i)
                    {
                        for (int k = 1; k <= p; k ++)
                        {
                            ans[0][j * (p + 3) + k] = '-';
                        }
                    }
                    else if (1 == i)
                    {
                        for (int k = 1; k <= p; k ++)
                        {
                            ans[k][j * (p + 3)] = '|';
                        }
                    }
                    else if (2 == i)
                    {
                        for (int k = 1; k <= p; k ++)
                        {
                            ans[k][j * (p + 3) + p + 1] = '|';
                        }
                    }
                    else if (3 == i)
                    {
                        for (int k = 1; k <= p; k ++)
                        {
                            ans[p + 1][j * (p + 3) + k] = '-';
                        }
                    }
                    else if (4 == i)
                    {
                        for (int k = 1; k <= p; k ++)
                        {
                            ans[p + 1 + k][j * (p + 3)] = '|';
                        }
                    }
                    else if (5 == i)
                    {
                        for (int k = 1; k <= p; k ++)
                        {
                            ans[p + 1 + k][j * (p + 3) + p + 1] = '|';
                        }
                    }
                    else if (6 == i)
                    {
                        for (int k = 1; k <= p; k ++)
                        {
                            ans[2 * p + 2][j * (p + 3) + k] = '-';
                        }
                    }
                }
            }
        }


        for (int i = 0; i <= 2 * p + 2; i ++)
        {
           // printf(" ");
            for (int j = 0; j <= (len - 1) *(p + 3) + p + 2; j ++)
            {
                printf("%c", ans[i][j]);
            }
            if (i == p + 1 || i == 2 * p + 2 || 0 == i) printf(" ");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
