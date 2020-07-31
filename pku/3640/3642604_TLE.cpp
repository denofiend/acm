//

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define MAXN 100001
using namespace std;

int n;
string frosh[MAXN];

string in[5];
map<string, int> ::iterator iter;
map<string, int> hash;

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
    hash.clear();
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
    cout << sum << endl;
}

int main(){
    while (cin >> n)
    {
        if (0 == n) break;
        input();
        solve();
    }
    return 0;
}

