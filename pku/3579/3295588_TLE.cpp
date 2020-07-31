// 3579(pku)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100010

__int64 a[MAXN];

using namespace std;

__int64 n;
__int64 ABS(__int64 a){ return a < 0 ? (-a) : a;  }


void input(){
    for (int i = 0; i < n; i ++)
    {
        scanf("%I64d", &a[i]);
    }
}
void solve(){
    __int64 det = n * (n - 1) / 2;
    if (0 == det % 2)
    {
        det /= 2;
        det --;
    }
    else
    {
        det /= 2;
    }
    priority_queue<__int64, vector<__int64>, greater<__int64> > media;
    for (int i = 0; i < n; i ++)
    {
        for (int j = i + 1; j < n; j ++)
        {
            long long diff = a[i] - a[j];
            diff = ABS(diff);
            media.push(diff);
        }
    }
    while (det)
    {
        media.pop();
        det --;
    }
    long long num = media.top();
    printf("%I64d\n", num);
}
int main(){
    while (EOF != scanf("%I64d", &n))
    {
        input();
        solve();
    }
    return 0;
}
