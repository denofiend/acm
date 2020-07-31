//

#include <iostream>

using namespace std;

int ans[1000];

int main(){
    int n, i, j;
    while (cin >> n)
    {
        for (i = 2, j = 0; ;i ++, j ++)
        {
            if (n <= i - 1) break;
            ans[j] = i;
            n -= i;
        }

        while (n)
        {
            for (i = j - 1; i >= 0 && n; i --)
            {
                ans[i]++;
                n --;
            }
        }
        for (i = 0; i < j; i ++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
