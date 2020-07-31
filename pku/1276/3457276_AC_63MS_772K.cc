//
//
//
//    procedure CompletePack(cost,weight)
//        for v=cost..V
//            f[v]=max{f[v],f[v-c[i]]+w[i]}
//
//
//
//    procedure ZeroOnePack(cost,weight)
//        for v=V..cost
//            f[v]=max{f[v],f[v-cost]+weight}
//
//
//    procedure MultiplePack(cost,weight,amount)
//        if cost*amount>=V
//            CompletePack(cost,weight)
//            return
//        integer k=1
//        while k<amount
//            ZeroOnePack(k*cost,k*weight)
//            amount=amount-k
//            k=k*2
//        ZeroOnePack(amount*cost,amount*weight)

#include <iostream>
#define MAXN 1001
#define MAXX 100001
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0 ; i < n; i ++)   out(x[i], m);   cout << endl;   }

int V, n;
int f[MAXX];
int cashn[MAXN], cashm[MAXN];

void completePack(int cost, int weight){
    for (int v = cost; v <= V; v ++)
    {
        f[v] = max(f[v], f[v - cost] + weight);
    }
}
void zeroOnePack(int cost, int weight){
   // printf("<%d %d>\n", cost, weight);
    for (int v = V; v >= cost; v --)
    {
        f[v] = max(f[v], f[v - cost] + weight);
    }
}
void multiplePack(int cost, int weight, int amount){
    //printf("[%d %d %d]\n", cost, weight, amount);
    if (cost * amount >= V)
    {
        completePack(cost, weight);
        return;
    }
    int k = 1;
    while (k < amount)
    {
        zeroOnePack(k * cost, k * weight);
        amount -= k;
        k *= 2;
    }
    zeroOnePack(amount * cost, amount * weight);
    //out(f, V + 1);
}
int main(){
    while (2 == scanf("%d %d", &V, &n))
    {
        for (int i = 1; i <= n; i ++)   scanf("%d %d", &cashn[i], &cashm[i]);
        for (int i = 0; i <= V; i ++)   f[i] = 0;

        for (int i = 1; i <= n; i ++)
            multiplePack(cashm[i], cashm[i], cashn[i]);
        printf("%d\n", f[V]);
    }
    return 0;
}
