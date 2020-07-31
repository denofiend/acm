// 1014(pku):双向DP

#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out(x[i], m);   cout << endl;   }

const int M = 200001;
int a[10];
int f[10][M];

bool dp(int sum){
    int i, j, k, val;
    if (1 & sum)    return false;
    sum >>= 1;
    for (i = 0; i <= 7; i ++)
        for (j = 0; j <= sum + 1; j ++)
            f[i][j] = 0;
    for (i = 0; i <= 7; i ++) f[i][0] = 1;

    // 1...3
    for (i = 1; i <= 3; i ++)
    {
        for (j = sum; j >= 0; j --)
        {
            if (f[i - 1][j])
            {
                f[i][j] = f[i - 1][j];
                for (k = 1; k <= a[i]; k ++)
                {
                    val = j + k * i;
                    if (f[i][val] || val > sum)    break;
                    f[i][val] = 1;
                }
            }
        }
    }

    //6..4
    for (i = 6; i >= 4; i --)
    {
        for (j = sum; j >= 0; j --)
        {
            if (f[i + 1][j])
            {
                f[i][j] = f[i + 1][j];
                for (k = 1; k <= a[i]; k ++)
                {
                    val = j + k * i;
                    if (f[i][val] || val > sum)    break;
                    f[i][val] = 1;
                }
            }
        }
    }

    // 判断是否Mid = sum / 2价值的两堆大理石
    for (k = 0; k <= sum; k ++)
        if ((f[3][k] && f[4][sum - k]) || (f[3][sum - k] && f[4][k]))
        {
            return true;
        }
    return false;

}

int main(){
    int sum, i, testcase = 1;
    while (EOF != scanf("%d %d %d %d %d %d\n", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]))
    {
        if (0 == a[1] && 0 == a[2] && 0 == a[3] && 0 == a[4] && 0 == a[5] && 0 == a[6]) break;
        sum = 0;
        for (i = 1; i <= 6; i ++)    sum += a[i] * i;

        if (dp(sum))
        {
            printf("Collection #%d:\nCan be divided.\n\n", testcase++);
        }
        else
        {
            printf("Collection #%d:\nCan't be divided.\n\n", testcase++);
        }
    }
    return 0;
}

