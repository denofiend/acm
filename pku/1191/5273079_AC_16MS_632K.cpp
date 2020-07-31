#include <iostream>
#include <cmath>
using namespace std;

typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;

int n;
int a[9][9], g[9][9];
int f[16][9][9][9][9];

// 计算(x1, y1, x2, y2)所占的分值和
inline int sum(int x1, int y1, int x2, int y2){
    return (g[x2][y2] - g[x1 - 1][y2] - g[x2][y1 - 1] + g[x1 - 1][y1 - 1])
        * (g[x2][y2] - g[x1 - 1][y2] - g[x2][y1 - 1] + g[x1 - 1][y1 - 1]);
}
// 递归求解原问题
int dp(int k, int x1, int y1, int x2, int y2){
    if (f[k][x1][y1][x2][y2] != maxint)
        return f[k][x1][y1][x2][y2];
    if (k == 1)
        return f[k][x1][y1][x2][y2] = sum(x1, y1, x2, y2);
    if (x1 == x2 && y1 == y2)
        return f[k][x1][y1][x2][y2] = sum(x1, y1, x2, y2);
    int ret = maxint;
	// 横切棋盘产生新的子问题(切了以后新产生的矩形)并计算当前问题
    for (int i = x1; i < x2; i++)
    {
		ret = ret <= dp(k - 1, x1, y1, i, y2) + sum(i + 1, y1, x2, y2) ? ret : dp(k - 1, x1, y1, i, y2) + sum(i + 1, y1, x2, y2);
		ret = ret <= sum(x1, y1, i, y2) + dp(k - 1, i + 1, y1, x2, y2) ? ret : sum(x1, y1, i, y2) + dp(k - 1, i + 1, y1, x2, y2);
    }
	// 纵切棋盘产生新的子问题(切了以后新产生的矩形)并计算当前问题
    for (int i = y1; i < y2; i++)
    {
		ret = ret <= dp(k - 1, x1, y1, x2, i) + sum(x1, i + 1, x2, y2) ? ret : dp(k - 1, x1, y1, x2, i) + sum(x1, i + 1, x2, y2);
		ret = ret <= sum(x1, y1, x2, i) + dp(k - 1, x1, i + 1, x2, y2) ? ret : sum(x1, y1, x2, i) + dp(k - 1, x1, i + 1, x2, y2);
    }
    return f[k][x1][y1][x2][y2] = ret;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            scanf("%d", &a[i][j]);
    memset(g, 0, sizeof(g));

    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + a[i][j];

    for (int k = 0; k <= 15; k++)
        for (int x1 = 1; x1 <= 8; x1++)
            for (int y1 = 1; y1 <= 8; y1++)
                for (int x2 = 1; x2 <= 8; x2++)
                    for (int y2 = 1; y2 <= 8; y2++)
                        f[k][x1][y1][x2][y2] = maxint;
    
	// 计算x的平均值的平方
    double sum = 0.0;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            sum += a[i][j];
    sum /= n;
    sum *= sum;

    printf("%.3lf\n", sqrt(dp(n, 1, 1, 8, 8) / double(n) - sum));
    return 0;
}
