// 3579(pku)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100010

long long a[MAXN];

using namespace std;

long long n;
long long ABS(long long a){ if (a < 0)  return (-a);    else return a;  }


void input(){
    for (int i = 0; i < n; i ++)
    {
        scanf("%I64d", &a[i]);
    }
}
void solve(){
    long long det = n * (n - 1) / 2;
    if (0 == det % 2)
    {
        det /= 2;
        det --;
    }
    else
    {
        det /= 2;
    }
    priority_queue<long long, vector<long long>, greater<long long> > media;
    for (int i = 0; i < n - 1; i ++)
    {
        for (int j = i + 1; j < n; j ++)
        {
            long long diff = ABS(a[i] - a[j]);
            if (media.empty())
            {
                media.push(diff);
            }
            else
            {
                if (det)
                {
                    long long num = media.top();
                    if (diff >= num)
                    {
                        media.push(diff);
                    }
                    else det --;
                }
                else
                {
                   media.push(diff);
                }
            }
        }
    }
    while (det)
    {
        media.pop();
        det --;
    }
    long long num = media.top();
    printf("%I64d\n", num);
}
int main(){
    while (1 == scanf("%I64d", &n))
    {
        input();
        solve();
    }
    return 0;
}
