// Moving Tables

#include <iostream>
#define NoEff(i, j) (from[i] >= to[j] || from[j] >= to[i])
using namespace std;

int from[201], to[201];

int flag[201];
int main(){
    int t;
    cin >> t;
    while (t --)
    {
        int n;
        cin >> n;
        int i;
        for (i = 0; i < n; i ++)
        {
            cin >> from[i] >> to[i];
            if (from[i] > to[i])
            {
                from[i] += to[i];
                to[i] = from[i] - to[i];
                from[i] -= to[i];
            }
            flag[i] = 0;
        }
        int j, num, ans = 0;
        for (i = 0; i < n; i ++)
        {
            if (0 == flag[i])
            {
                ans += 10;
                flag[i] = 1;
                num = 0;
                for (j = i + 1; j < n; j ++)
                    if (0 == flag[j] && NoEff(i, j))
                    {
                        //ans += 10;
                        flag[j] = 1;
                    }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
