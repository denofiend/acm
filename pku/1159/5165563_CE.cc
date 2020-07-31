//


#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; ++i) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; ++i)  out(x[i], m);      cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b) FOR(i, 0, b)
#define FORD(i, a, b)    for(int i = (int)a; i >= (int)b; --i)
#define MAXN 5001

int f[MAXN][MAXN];
char s[MAXN];
int n;

int main(){
    while (EOF != scanf("%d", &n))
    {
          scanf("%s", s);
          REP (i, n)  f[i][i] = 0;
          FOR (k, 1, n)
          {
              REP (i, n-k+1)
              {
                  int j = i+k;
                  // [i, j]
                  if (s[i] == s[j])  f[i][j] = f[i+1][j-1];
                  else f[i][j] = min(f[i+1][j], f[i][j-1]) + 1;
              }
          }
          printf("%d\n", f[0][n-1]);
    }
    return 0;
}
