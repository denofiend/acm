//


#include <iostream>
#include <algorithm>

using namespace std;

char str[20];
char output[20];
int num[20];

int main(){
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n --)
    {
        scanf("%s", str);
        int len = strlen(str);
        int j = 0, cnt = 0;
        for (char a = 'A'; a <= 'Z'; a ++)
        {
            for (int i = 0; i < len; i ++)
            {
                if (a == str[i])
                {
                    output[j] = a;
                    num[j] = j;
                    j++;
                }
            }
            for (int i = 0; i < len; i ++)
            {
                if (a + 32 == str[i])
                {
                    output[j] = a + 32;
                    num[j] = j;
                    j++;
                }
            }
        }
        for (int i = 0; i < len; i ++)
        {
            printf("%c", output[num[i]]);
        }
        printf("\n");
        while (next_permutation(num,  num + len))
        {
            for (int i = 0; i < len; i ++)
            {
                printf("%c", output[num[i]]);
            }
            printf("\n");
        }

    }
    return 0;
}
