// 1061(pku)

#include <iostream>

using namespace std;

int main(){
    int x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    if (x != y && m == n)   printf("Impossible\n");
    else
    {
        int ans = 0;
        while (x != y)
        {
            x = (x + m) % L;
            y = (y + n) % L;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
