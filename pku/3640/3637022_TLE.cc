//

#include <iostream>
#include <map>
#include <string>
#define MAXN 10001
using namespace std;

int n;
string frosh[MAXN];

string in[5];

void input(){
    //memset(frosh, 0, sizeof(frosh));
    for (int i = 0; i < n; i ++)
    {
        cin >> in[0] >> in[1] >> in[2] >> in[3] >> in[4];
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
        //cout << iter->first << ' ' << iter->second << endl;
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

