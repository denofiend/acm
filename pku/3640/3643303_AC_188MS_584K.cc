// 3640(pku)
//

#include <iostream>
#include <algorithm>
#define MAXN 100001
using namespace std;


template <class T> void out(T x, int n){    for (int i = 0; i < n; i ++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

struct Stu{
    int id[5];
};

Stu stu[MAXN];
int idd[1000];

int n;
bool input(){
    scanf("%d", &n);
    if (0 == n) return false;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < 5; j ++)
        {
            scanf("%d", &stu[i].id[j]);
        }
        sort(stu[i].id, stu[i].id + 5);
    }
    return true;
}

// O(n)方法
bool operator == (const Stu &a, const Stu &b){
    int i;
    for (i = 0; i < 5; i ++)
    {
        if (a.id[i] != b.id[i])
        {
            return false;
        }
    }
    return true;
}

bool operator < (const Stu &a, const Stu &b){
    int i;
    for (i = 0; i < 5; i ++)
    {
        if (a.id[i] < b.id[i])
        {
            return true;
        }
        else if (a.id[i] > b.id[i])
        {
            return false;
        }
    }
    return false;
}

void solve(){
    int ans = 0, cnt = 0, i, counts = 0, maxn;
    sort(stu, stu + n);

    Stu tmp = stu[0];
    for (i = 0; i < n; i ++)
    {
        if (tmp == stu[i])
        {
            counts++;
        }
        else
        {
            idd[cnt++] = counts;
            counts = 1;
            tmp = stu[i];
        }
    }
    idd[cnt++] = counts;

    sort(idd, idd + cnt);
    //out(idd, cnt);

    maxn = idd[cnt - 1];
    for (i = cnt - 1; i >= 0; i --)
    {
        if (maxn == idd[i])
        {
            ans += maxn;
        }
    }
    printf("%d\n", ans);
}

int main(){
    while (input())
    {
        solve();
    }
    return 0;
}
