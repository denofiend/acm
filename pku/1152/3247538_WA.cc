// 1162(pku)

#include <iostream>
#define MAXN 100000
using namespace std;


char num[MAXN];

int main(){
    while (1 == scanf("%s\n", num))
    {
        int i = 0, len = strlen(num), base = 1, j;
        for (; i < len; i ++)
        {
            //printf("<%c, base = %d, %d>\n", num[i], base, num[i] - 'a' + 37);
            if ('A' <= num[i] && num[i] <= 'Z')
            {
                if (base < num[i] - 'A' + 12)
                    base = num[i] - 'A' + 12;
            }
            else if ('a' <= num[i] && num[i] <= 'z')
            {
                if (base < num[i] - 'a' + 38)
                    base = num[i] - 'a' + 38;
            }
            else if (base < num[i] - '0' + 1)
                base = num[i] - '0' + 1;
            //printf("(%c, base = %d, %d)\n", num[i], base, num[i] - 'a' + 37);
        }
        long long sum = 0;
        for (j = 0; j < len; j ++)
        {

            if ('A' <= num[j] && num[j] <= 'Z')
                sum += num[j] - 'A' + 11;
            else if ('a' <= num[j] && num[j] <= 'z')
                sum += num[j] - 'a' + 37;
            else
                sum += (num[j] - '0');
        }
        for (i = base; i <= 62 && base >= 2; i ++)
        {
            if (0 == sum % (i - 1))
                break;
        }
        //printf("sum = %I64d, base = %d, i = %d\n", sum, base, i);
        if(base > 62 || base < 2 || i > 62)   printf("such number is impossible!\n");
        else if (i <= 62)    printf("%d\n", i);
    }
    return 0;
}
