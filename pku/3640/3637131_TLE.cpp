//

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define MAXN 10001
using namespace std;

int n;
string frosh[MAXN];

string in[5];

char inn[10][10];

void input(){
    for (int i = 0; i < n; i ++)
    {
        scanf("%s %s %s %s %s", inn[0], inn[1], inn[2], inn[3], inn[4]);
        //printf("%s %s %s %s %s\n", inn, inn + 1, inn + 2, inn + 3, inn + 4);
        for (int j = 0; j < 5; j ++)
            in[j] = inn[j];

        sort(in, in + 5);
        frosh[i].clear();
        for (int j = 0; j < 5; j ++)
            frosh[i] += in[j];
    }
}

void solve(){
    map<string, int> hash;
    for (int i = 0; i < n; i ++)
    {
        if (hash.end() == hash.find(frosh[i]))
        {
            hash[frosh[i]] = 1;
        }
        else
        {
            hash[frosh[i]] ++;
        }
    }
    int ans = -1;
    map<string, int> ::iterator iter;
    for (iter = hash.begin(); iter != hash.end(); iter++)
    {
        if (iter->second > ans)
        {
            ans = iter->second;
        }
    }
    int sum = 0;
    for (iter = hash.begin(); iter != hash.end(); iter++)
    {
        if (ans == iter->second)
        {
            sum += iter->second;
        }
    }
    printf("%d\n", sum);
}

int main(){
    while (EOF != scanf("%d", &n))
    {
        if (0 == n) break;
        input();
        solve();
    }
    return 0;
}

