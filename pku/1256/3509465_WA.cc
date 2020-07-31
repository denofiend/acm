//


#include <iostream>
#include <algorithm>

using namespace std;

char str[20];
char output[20];

int main(){
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n --)
    {
        scanf("%s", str);
        int len = strlen(str);
        int j = 0;
        for (char a = 'A'; a <= 'Z'; a ++)
        {
            for (int i = 0; i < len; i ++)
            {
                if (a == str[i])
                {
                    output[j++] = a;
                }
            }
            for (int i = 0; i < len; i ++)
            {
                if (a + 32 == str[i])
                {
                    output[j++] = a + 32;

                }
            }
        }

        printf("%s\n", output);
        while (next_permutation(output,  output + len))
        {
            printf("%s\n", output);
        }
    }
    return 0;
}
