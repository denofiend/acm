// 1094
//
//

#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; ++i) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; ++i) out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for (int i = (int)a; i >= (int)b; --i)

int main(){
    int n, m, i, j, k, l, d[26][26];
    int flag, inco;
    char c1, c, c2;
    char letter[27];
    int count;

    while (cin >> n >> m && n && m)
    {
        memset(d, 0, sizeof(d));
        for (i = 0; i < n; i++) letter[i] = (char)('A'+i);

        letter[i] = inco = flag = 0;

        for (i = 0; i < m; i++)
        {
            cin >> c1 >> c >> c2;
            if (flag || inco) continue;

            d[c1-'A'][c2-'A'] = 1;

            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    for (l = 0; l < n; l++)
                        if (d[k][j] && d[j][l]) d[k][l] = 1;

            count = 0;
            for (j = 0; j < n; j++)
            {
                for (k = j; k < n; k++)
                {
                    if (d[j][k] && d[k][j])
                    {
                        cout << "Inconsistency found after " << i+1 << " relations.\n";
                        inco = 1;
                        break;
                    }
                    if (d[j][k] || d[k][j]) count++;
                }
                if (inco) break;
            }
            if (inco) continue;
            if (count == n*(n-1)/2)
            {
                cout << "Sorted sequence determined after " << i+1 << " relations: ";
                flag = 1;
            }
        }
        if (inco) continue;
        if (count != n*(n-1)/2)
        {
            cout << "Sorted sequence cannot be determined.\n";
            continue;
        }
        for (i = 0; i < n; i++)
        {
            for (j = i+1; j < n; j++)
            {
                if (d[letter[j]-'A'][letter[i]-'A'] )
                {
                    letter[i] ^= letter[j];
                    letter[j] = letter[i]^letter[j];
                    letter[i] ^= letter[j];
                }
            }
        }
        cout<<letter<<".\n";
    }
    return 0;
}
