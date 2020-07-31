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
    int m = n / 2;
    for (int j1 = 1, m1 = 1; j1 <= maxx && m1 <= m; j1 ++)
    {
        if (m == m1)
        {
            long long sum = 0;

            sum += k[1] * product[j1][p[1]];

            addHash(-sum);
        }
        for (int j2 = 1, m2 = m1 + 1; j2 <= maxx && m2 <= m; j2 ++)
        {
            if (m == m2)
            {
                long long sum = 0;

                sum += k[1] * product[j1][p[1]] + k[2] * product[j2][ p[2] ];

                addHash(-sum);
            }
            for (int j3 = 1, m3 = m2 + 1; j3 <= maxx && m3 <= m; j3 ++)
            {
                if (m3 == m)
                {
                    long long sum = 0;
                    sum += k[1] * product[j1][p[1]] + k[2] * product[j2][p[2]] + k[3] * product[j3][p[3]];
                    addHash(-sum);
                }
            }
        }
    }
    int cnt = 0;
    m = n;
    for (int j1 = 1, m1 = n / 2 + 1; j1 <= maxx && m1 <= m; j1 ++)
    {
        if (m == m1)
        {
            long long sum = 0;

            sum += k[1] * product[j1][p[1]];

            if (hash1.end() != hash1.find(sum))
                cnt += hash1[sum];
        }
        for (int j2 = 1, m2 = m1 + 1; j2 <= maxx && m2 <= m; j2 ++)
        {
            if (m == m2)
            {
                long long sum = 0;

                sum += k[1] * product[j1][p[1]] + k[2] * product[j2][ p[2] ];

                if (hash1.end() != hash1.find(sum))
                    cnt += hash1[sum];
            }
            for (int j3 = 1, m3 = m2 + 1; j3 <= maxx && m3 <= m; j3 ++)
            {
                if (m == m3)
                {
                    long long sum = 0;
                    sum += k[1] * product[j1][p[1]] + k[2] * product[j2][p[2]] + k[3] * product[j3][p[3]];
                    if (hash1.end() != hash1.find(sum))
                        cnt += hash1[sum];
                }
            }
        }
    }
    printf("%d\n", cnt);
}

int main(){
    init();
    hash();
    return 0;
}
