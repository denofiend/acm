// 1063(pku)
//

#include <iostream>

using namespace std;

int main(){
    int t, n, c, i, j, cnt, cnt1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0, j = 0, cnt = 0, cnt1 = 0; i < n; i ++)
        {
            cin >> c;
            if (1 == c)
            {
                if (0 == i % 2)
                {
                    cnt++;
                }
                else
                {
                    cnt1++;
                }
            }
        }
        i = cnt - cnt1;
        if (1 == n % 2)
        {
            printf("YES\n");
            continue;
        }

        if (i > -2 && i < 2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
