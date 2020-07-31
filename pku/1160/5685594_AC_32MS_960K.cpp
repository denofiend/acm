//
//


#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <queue>


using namespace std;

template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)



#include<iostream>
#include<algorithm>
using namespace std;
int x[320];
int dp[320][32];
int f[320][320];
int s[320][320];
int main()
{
    int i,j,k;
    int v,p;
    scanf("%d%d",&v,&p);
    for(i=1;i<=v;++i)
        scanf("%d",&x[i]);
    for(i=1;i<=v;++i)
    {
        for(j=i+1;j<=v;++j)
        {
            f[i][j]=0;
            int s=(i+j)/2;
            for(k=i;k<=j;++k)
                f[i][j]+=abs(x[s]-x[k]);
        }
    }
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=v;++i)
    {
        dp[i][1]=f[1][i];
        s[i][1]=1;
    }
    for(j=2;j<=p;++j)
    {
        for(k=s[v][j-1];k<v;++k)
        {
            if(dp[v][j]==-1||dp[k][j-1]+f[k+1][v]<dp[v][j])
            {
                dp[v][j]=dp[k][j-1]+f[k+1][v];
                s[v][j]=k;
            }
        }
        for(i=v-1;i>0;--i)
        {
            for(k=s[i][j-1];k<=s[i+1][j];++k)
                if(dp[i][j]==-1||dp[k][j-1]+f[k+1][i]<dp[i][j])
                {
                    dp[i][j]=dp[k][j-1]+f[k+1][i];
                    s[i][j]=k;
                }
        }
    }
    printf("%d\n",dp[v][p]);
    return 0;
}
