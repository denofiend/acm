//

#include <iostream>
#include <algorithm>
#define MAXN 20001
using namespace std;

int a[MAXN];

bool cmp(int a, int b){
    if (a < b)  return true;
    else return false;
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++)    scanf("%d", &a[i]);

        sort(a, a + n, cmp);

        int sum = 0;
        for (int i = n - 3; i >= 0; i -= 3)
            sum += a[i];

        printf("%d\n", sum);
    }
    return 0;
}
