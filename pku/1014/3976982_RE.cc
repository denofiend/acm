//


#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out(x[i], m);   cout << endl;   }

const int M = 100001;
int a[7];
int f[7][M];
void dp(int sum){
    int i, j, k;
    for (i = 0; i <= 7; i ++)
        for (j = 0; j <= sum; j ++)
            f[i][j] = 0;
    for (i = 0; i <= 7; i ++) f[i][0] = 1;

    for (i = 1; i <= 6; i ++)
    {
        for (j = 0; j <= sum; j ++)
        {
            for (k = 1; k <= a[i]; k ++)
            {
                if (j - i * k < 0)  continue;
                if (i <= 3)
                {
                    if (f[i - 1][j - i * k])
                    {
                        f[i][j] = 1;
                        break;
                    }

                }
                else
                {

                    if (f[i + 1][j - i * k])
                    {
                        f[i][j] = 1;
                        break;
                    }

                }
            }
        }
    }
    //out(f, 7, sum + 1);
    for (k = 0; k <= sum; k ++)
        if (f[3][k] && f[6][sum - k])
        {
            printf("Can be divided.\n\n");
            break;
        }
    if (k == sum + 1)
    {
        printf("Can't be divided.\n\n");
    }
}

int main(){
    int sum, i, testcase = 1;
    while (EOF != scanf("%d %d %d %d %d %d\n", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]))
    {
        sum = 0;
        for (i = 1; i <= 6; i ++)    sum += a[i] * i;
        if (0 == sum)   break;
        printf("Collection #%d:\n", testcase++);
        if (1 & sum)    printf("Can't be divided.\n\n");

        sum /= 2;
        dp(sum);
    }
    return 0;
}
