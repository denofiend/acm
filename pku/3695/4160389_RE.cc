#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

set<int> V[10001];

bool B[10001];

int N, M, T = 1;

deque<int> Q;

list<int> S;

int main() {

    while(cin >> N >> M && N) {
        for(int i = 1; i <= N; ++i)
            V[i].clear();
        for(int i = 0; i < M; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if(x > y) swap(x, y);
            V[x].insert(y);
        }
        S.clear();
        for(int i = 2; i <= N; ++i)
            S.push_back(i);
        Q.push_back(1);
        int ans = 0, x, y, p, q;
        while(!Q.empty()) {
            x = Q.front();
            Q.pop_front();
            for(list<int>::iterator it = S.begin(); it != S.end();) {
                y = *it;
                p = min(x, y);
                q = max(x, y);
                if(V[p].find(q) == V[p].end()) {
                    Q.push_back(y);
                    it = S.erase(it);
                    ++ans;
                }
                else ++it;
            }
        }
        printf("Case %d: ", T++);
        cout << ans << endl;
    }

}
