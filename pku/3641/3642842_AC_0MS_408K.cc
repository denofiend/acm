#include <iostream>
using namespace std;
#define INT long long
typedef long long L;

bool IsPri(int n){
    if (n <= 3)
       return true;
    if (n > 2 && ! (n % 2))
       return false;
    for (int i = 3; i * i <= n;i += 2)
    {
       if (!(n % i))
        return false;
    }
    return true;
}


INT square(INT x){    return x * x;   }

INT bigmod(INT b, INT p, INT m) {
    if (0 == p)
        return 1;
    else if (0 == p % 2)
        return square(bigmod(b, p / 2, m)) % m; // square(x) = x * x
    else
        return ((b % m) * bigmod(b, p-1, m)) % m;
}
int main(){
    INT p, a;
    while (cin >> p >> a, p || a)
    {
       if (IsPri(p))
       {
        puts("no");
        continue;
       }
       puts(bigmod(a, p, p) == a ? "yes" : "no");
    }
    return 0;
}
