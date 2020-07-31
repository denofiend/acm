//
// DP
//

#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i++) cout << x[i] << ' ';    cout << endl;    }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out (x[i], m);  cout << endl;   }

#define STATE (6*6*6*6*6)
#define INF (1<<29)
#include "stdio.h"
#include "memory.h"
int F[STATE];
int b,s;
int product[5][3]; // 0 code, 1 item numbers ,2 price
int mapcode[1000]; // map product code to 0,1,2,3,4;
int offer[105][5];
int offerprice[105];
int minprice=INF;

int getnum(int a[5]){
    int i, sum = 0;
    for (i = 4; i >= 0; --i)
        sum = sum * 6 + a[i];
    return sum;
}

void getcode(int num, int a[5]){
    int i = 0;
    while (num)
    {
        a[i++] = num % 6;
        num /= 6;
    }
    for (; i < 5; ++i) a[i] = 0;
}

int canbetransferd(int a[5], int b[5]){
    int i;
    for (i = 0; i < 5; ++i)
        if (a[i] < b[i]) break;
    return i == 5;
}

int main(){
    int i, j;
    int pc, quantity;
    int num;
    for(i=0;i<STATE;++i)
       F[i]=INF;
    scanf("%d", &b);
    for (i = 0; i < b; ++i)
    {
       scanf("%d %d %d", &product[i][0], &product[i][1], &product[i][2]);
       mapcode[product[i][0]] = i;
    }
    scanf("%d", &s);
    for (i = 0; i < s; ++i)
    {
        scanf("%d", &num);
        for (j = 0; j < num; ++j)
        {
            scanf("%d %d", &pc, &quantity);
            offer[i][ mapcode[pc] ] = quantity;
        }
        scanf("%d", &offerprice[i]);
    }

    for (; i < b + s; ++i)
    {
       memset(offer[i], 0, sizeof(offer[i]));
       offer[i][i-s] = 1;
       offerprice[i] = product[i-s][2];
    }

    int temp[5];
    for (i = 0; i < 5; ++i)
       temp[i] = product[i][1];
    int st = getnum(temp);
    F[st] = 0;
    for (i = st; i > 0; --i)
    {
        getcode(i, temp);
        for (j = 0; j < s + b; ++j)
        {
            if (canbetransferd(temp, offer[j]))
            {
                int newst[5];
                for (int k = 0; k < 5; ++k)
                    newst[k] = temp[k] - offer[j][k];
                int nst = getnum(newst);
                if (F[nst] > F[i] + offerprice[j]) F[nst] = F[i] + offerprice[j];
            }
        }
    }
    printf("%d\n", F[0]);
    return 0;
}
