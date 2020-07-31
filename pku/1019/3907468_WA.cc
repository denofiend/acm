//

#include <iostream>

using namespace std;

int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int nLen(int n){
    int ret = 0;
    while (n)
    {
        ret ++;
        n /= 10;
    }
    return ret;
}

int getN(int n){
    int i, m;
    for (i = 1; ; i ++)
    {
        m = nLen(i);
        if (n <= m) break;
        n -= m;
    }
    return (i / pow10[m - n]) % 10;
}

int getLen(int n){
    int ret = 0, i, len = nLen(n);
    //if (10 == n)
    //    printf("len = %d\n", len);
    for (i = 1; i < len; i ++)
    {
        //if (n <= pow10[i])  break;
        ret = 9 * pow10[i - 1] * i;
    }
    ret += len * (n - pow10[len - 1] + 1);
    return ret;

}
int solve(int n){
    int i, m;
    for (i = 1; ; i ++)
    {
        m = getLen(i);
        if (n <= m)  break;
        n -= m;

    }
    return getN(n);
}

int main(){
    int t, n;
    //for (int i = 1; i <= 10; i ++)
    //    printf("%d ", getLen(i));
    scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}

