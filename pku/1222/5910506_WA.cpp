//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;


template <class T> void out(T x, int n){	for(int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for(int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)

int a[30];
int b[30];
int c[30];
int res[30];
int dirt[4][2] = {0,1,0,-1,1,0,-1,0};
bool jie(int x, int y)
{
    if (x < 0 || y < 0 || x > 4 || y > 5)
        return false;
    return true;
}
void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int n;
    scanf("%d",&n);
    int cases = 0;
    while (n--)
    {
        cases++;
        for (int i = 0; i < 30; ++i)
        {
            scanf("%d", &a[i]);
            //a[i] = (a[i]+1)%2;
        }
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int tx, ty;
        for (int i = 0; i < 30; ++i)
        {
            tx = i/6;
            ty = i%6;
            b[i] += 1<<i;
            for (int j = 0; j < 4; ++j)
            {
                tx += dirt[j][0];
                ty += dirt[j][1];
                if (jie(tx,ty))
                {
                    b[i] += (1<<(tx*6+ty));
                }
                tx -= dirt[j][0];
                ty -= dirt[j][1];
            }
        }
        
        for (int i = 0; i < 30; ++i)
        {
            for (int j = 0; j < 30; ++j)
            {
                if (((1<<j)&b[i]) == 0)
                    cout << 0;
                else
                    cout << 1;
            }
            cout << " " << a[i] << endl;
        }

        for (int i = 0; i < 30; ++i)
        {
            for (int j = i; j < 30; ++j)
            {
                if (((1<<i)&(b[j])) != 0)
                {
                    swap(a[j], a[i]);
                    swap(b[j], b[i]);
                    break;
                }
            }
            for (int j = i+1; j < 30; ++j)
            {
                if (((1<<i)&(b[j])) != 0)
                {
                    b[j] ^= b[i];
                    a[j] ^= a[i];
                }
            }
           
        }

        for (int i = 29; i >= 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (((1<<i)&(b[j])) != 0)
                {
                    b[j] ^= b[i];
                    a[j] ^= a[i];
                }
            }
        }
/*
        for (int i = 0; i < 30; ++i)
        {
            for (int j = 0; j < 30; ++j)
            {
                if (((1<<j)&b[i]) == 0)
                    cout << 0;
                else
                    cout << 1;
            }
            cout << " " << a[i] << endl;
        }
*/
        printf("PUZZLE #%d\n", cases);

        for (int i = 0; i < 30; ++i)
        {
            printf("%d", a[i]);
            if (i % 6 == 5)
                printf("\n");
            else
                printf(" ");
        }
       
    }
    return 0;
}