//


#define OUT(x) (cout << #x << " = " << x << endl)
#include <iostream>
#include <math.h>
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i++) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i++) out(x[i], m);   cout << endl;   }

void output(int n){
    int m = ceil((n+1)/2), i, j;
    for (i = m, j = 0; i+1 <= n; i++, j++)
    {
        printf("%d 2 %d\n", i, j);
    }
    printf("1 %d %d\n", j, j);
}

int main(){
    int n, m;
    while (EOF != scanf("%d", &n))
    {
        if (1 == n) printf("0\n");
        else if (2 == n)    printf("1\n1 1 1\n");
        else
        {
            if (1 & n)
            {
                m = ceil((n+1)/ 2);
                printf("%d\n", m);
                output(n);
            }
            else
            {
                printf("%d\n", n / 2);
                output(n-1);
                if (0 == n % 2) printf("%d 1 0\n", n);
            }
        }
    }
    return 0;
}

