// 1186(pku)
// hash

#include <iostream>
#include <map>
#define MAXN 151
#define MAXINT 3300000000

using namespace std;


int n;
int k[7], p[7];
long long product[MAXN][MAXN];
int maxx;
map<long long, int> hash1;


void init(){
    for (long long i = 1; i < MAXN; i ++)
    {
        product[i][1] = i;
        for (int j = 2; j < MAXN && product[i][j - 1] * i < MAXINT; j ++)
            product[i][j] = product[i][j - 1] * i;
    }
    scanf("%d", &n);
    scanf("%d", &maxx);
    for (int i = 1; i <= n; i ++)
        scanf("%d%d", &k[i], &p[i]);
}
void addHash(long long sum){
    if (hash1.end() == hash1.find(sum))    hash1[sum] = 1;
    else hash1[sum] ++;
}
void hash(){
    int m = n / 2 + 1;
    for (int j1 = 1, m1 = 1; j1 <= maxx && m1 <= m; j1 ++)
    {
        if (m == m1)
        {
            long long sum = 0;

            sum += k[m1] * product[j1][p[m1]];

            addHash(-sum);
        }
        for (int j2 = 1, m2 = m1 + 1; j2 <= maxx && m2 <= m; j2 ++)
        {
            if (m == m2)
            {
                long long sum = 0;

                sum += k[m1] * product[j1][p[m1]] + k[m2] * product[j2][ p[m2] ];

                addHash(-sum);
            }
            for (int j3 = 1, m3 = m2 + 1; j3 <= maxx && m3 <= m; j3 ++)
            {
                if (m3 == m)
                {
                    long long sum = 0;
                    sum += k[m1] * product[j1][p[m1]] + k[m2] * product[j2][p[m2]] + k[m3] * product[j3][p[m3]];
                    addHash(-sum);
                }
                for (int j4 = 1, m4 = m3 + 1; j4 <= maxx && m4 <= m; j4 ++)
                {
                    if (m4 == m)
                    {
                        long long sum = 0;
                        sum += k[m1] * product[j1][p[m1]] + k[m2] * product[j2][p[m2]] + k[m3] * product[j3][p[m3]] + k[m4] * product[j4][p[m4]];
                        addHash(-sum);
                    }
                }
            }
        }
    }
    int cnt = 0;
    if (1 == n) cnt = hash1[0];
    m = n;
    for (int j1 = 1, m1 = n / 2 + 2; j1 <= maxx && m1 <= m; j1 ++)
    {
        if (m == m1)
        {
            long long sum = 0;

            sum += k[m1] * product[j1][p[m1]];

            if (hash1.end() != hash1.find(sum))
                cnt += hash1[sum];
        }
        for (int j2 = 1, m2 = m1 + 1; j2 <= maxx && m2 <= m; j2 ++)
        {
            if (m == m2)
            {
                long long sum = 0;

                sum += k[m1] * product[j1][p[m1]] + k[m2] * product[j2][ p[m2] ];

                if (hash1.end() != hash1.find(sum))
                    cnt += hash1[sum];
            }
        }
    }
    //if (hash1.end() != hash1.find(0))   cnt += hash1[0];
    printf("%d\n", cnt);
}

int main(){
    init();
    hash();
    return 0;
}
