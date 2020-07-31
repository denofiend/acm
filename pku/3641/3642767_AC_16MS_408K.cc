#include <iostream>
using namespace std;

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

//calc the (a^p)%m
L BigMod(L a, L p, L m) {
    if (0 == a || 1 == m)
       return 0;
    if (0 == p)
       return 1;
    if(p % 2)
       return ((a % m) * BigMod(a, p-1, m)) % m;
    L tmp = BigMod(a, p/2, m);
    return (tmp * tmp) % m;
}

int main(){
    L p, a;
    while (cin >> p >> a, p || a)
    {
       if (IsPri(p))
       {
        puts("no");
        continue;
       }
       puts(BigMod(a,p,p)==a ? "yes" : "no");
    }
    return 0;
}
