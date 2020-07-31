// 3585(pku)

#include <iostream>
#include <string>
#define MAXN 2000

using namespace std;

string arr[MAXN];

int main(){
    string str;
    getline(cin, str);
    int size = 1;
    while (cin >> arr[size]) size++;

    int len = str.size();
    char str1[100], str2[100];
    int len1 = 0, len2 = 0;
    for (int i = 0; i < len; i ++)
    {
        if ('{' == str[i])
        {
            if (0 == len1)
            {
                for (int j = i + 1; j < len; j ++)
                {

                    if ('}' == str[j])
                    {
                        str1[len1] = '\0';
                        i = j;
                        break;
                    }
                    str1[len1++] = str[j];
                }
            }
            else if (0 == len2)
            {
                for (int j = i + 1; j < len; j ++)
                {

                    if ('}' == str[j])
                    {
                        str2[len2] = '\0';
                        i = j;
                        break;
                    }
                    str2[len2++] = str[j];
                }
            }
        }
    }


    //printf("%s\n%s\n", str1, str2);
    int i, j;
    char ans1[100], ans2[100];
    int an1 = 0, an2 = 0;
    for (i = 0; i < len1; i ++)
    {
        if ('\\' == str1[i])
        {
            i ++;
            continue;
        }
        ans1[an1++] = str1[i];
    }
    ans1[an1] = '\0';
    for (j = 0; j < len2; j ++)
    {
        if ('\\' == str2[j])
        {
            j ++;
            continue;
        }
        ans2[an2++] = str2[j];
    }
    ans2[an2] = '\0';
    //printf("%s\n%s\n", ans1, ans2);
    //printf("%d %d\n", an1, an2);
    int pos1 = ans1[an1 - 1] - '0', pos2 = ans2[an2 - 1] - '0';
    int base = 10;
    for (i = an1 - 2; i >= 0; i --)
    {
        pos1 += (ans1[i] - '0') * base;
        base *= 10;
    }
    for (j = an2 - 2; j >= 0; j --)
    {
        pos2 += (ans2[j] - '0') * base;
        base *= 10;
    }
    //printf("%d %d\n", pos1, pos2);

    for (i = 0; i < len; i ++)
    {
        cout << str[i];
        if ('{' == str[i] && pos1)
        {
            cout << arr[pos1];
            pos1 = 0;
            i += len1;
            continue;
        }
        if ('{' == str[i] && pos2)
        {
            cout << arr[pos2];
            pos2 = 0;
            i += len2;
            continue;
        }

    }
    cout << endl;
    return 0;
}
