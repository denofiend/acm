//

#include <iostream>
#define MAXN 5001
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }



unsigned long long ans[MAXN];

void init(){
    unsigned long long mod = (unsigned long long)(1) << 63;
    ans[1] = 1;
    ans[2] = 3;
    for (int i = 3; i < MAXN; i ++)
    {
        ans[i] = (11 * i * (2 * i - 1) * ans[i - 1] + 3 * (3 * i - 2) * (3 * i - 4) * ans[i - 2]) / (5 * i * (i +1));
        if (mod != ans[i])
            ans[i] %= mod;
    }
}
int main(){
    init();
    int n;
    while (1 == scanf("%d", &n))
    {
        printf("%I64u\n", ans[n - 2]);
    }
    return 0;
}
