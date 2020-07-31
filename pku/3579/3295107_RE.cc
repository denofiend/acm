// 3579(pku)

#include <iostream>
#include <map>
#define MAXN 100010

long long a[MAXN];

long long ans[MAXN * 10];


using namespace std;

int n;
long long ABS(long long a){ if (a < 0)  return (-a);    else return a;  }

int cmp(const void *a, const void *b){
    long long *aa = (long long *)a;
    long long *bb = (long long *)b;
    return *aa - *bb;
}
void input(){
    for (int i = 0; i < n; i ++)
    {
        scanf("%I64d", &a[i]);
    }
}
void solve(){
    int size = 0;
    for (int i = 0; i < n - 1; i ++)
    {
        for (int j = i + 1; j < n; j ++)
        {
            long long diff = ABS(a[i] - a[j]);
            ans[size++] = diff;
        }
    }
    qsort(ans, size, sizeof(ans[0]), cmp);
    printf("%I64d\n", ans[(size - 1) / 2]);
}
int main(){
    while (1 == scanf("%d", &n))
    {
        input();
        solve();
    }
    return 0;
}
