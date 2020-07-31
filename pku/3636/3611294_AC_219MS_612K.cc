#include<iostream>

#include<algorithm>

using namespace std;



typedef struct{
       int a,b;

}node;

node d[20001];

int temp[20001];



bool cmp(node x,node y)
{
    if (x.a != y.a) return x.a < y.a;

    else return x.b > y.b;

} //小到大一级，大到小二级



int main(){

    int t, n, i;

    int p, x, high, low;

    scanf("%d", &t);

    while(t--)

    {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
             scanf("%d%d", &d[i].a, &d[i].b);

        sort(d, d + n, cmp);

        p = 0;
        temp[p] = d[0].b;

        for (i = 1; i < n; i++)
        {

             if (d[i].b <= temp[p]) //先判断能否接上

             { p++; temp[p] = d[i].b; continue; }



             high = p, low = 0;

             while (high > low) //2分，不太会写
             {

                    x = (high + low) / 2;

                    if (temp[x] >= d[i].b) low = x + 1;

                    else high = x;

             }

             temp[low] = d[i].b;

        }
        printf("%d\n", p + 1);

    }

    return 0;

}
