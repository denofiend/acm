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
            if ('A' <= num[i] && num[i] <= 'Z' && base <= num[i] - 55)
                base = num[i] - 'A' + 10;
            else if ('a' <= num[i] && num[i] < 'z' && base <= num[i] - 61)
                base = num[i] - 'a' + 36;
            else if (base <= num[i] - '0')
                base = num[i] - '0' + 1;
        }
        int sum = 0;
        for (j = 0; j < len; j ++)
        {
            if ('A' <= num[j] && num[j] <= 'Z')
                sum += num[j] - 'A' + 10;
            else if ('a' <= num[i] && num[j] < 'z')
                sum += num[j] - 'z' + 36;
            else
                sum += (num[j] - '0');
        }
        for (i = base; i <= 62 && base >= 2; i ++)
        {
            if (0 == sum % (i - 1))
                break;
        }
        if (i <= 62)    printf("%d\n", i);
        else if(base > 62 || base < 2)   printf("such number is impossible!\n");
    }
    return 0;
}
