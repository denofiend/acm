//

#define OUT(x) (cout << #x << " = " << x << endl)
#include <iostream>
using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n;  i++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }


int main(){
    long long t, c, a[101], p[101], i, j, sum[101], s[101];
    cin >> t;
    while (t -- )
    {
        cin >> c;
        memset(sum, 0, sizeof(sum));
        for (i = 1; i <= c; i++)
        {
            cin >> a[i] >> p[i];
            sum[i] = sum[i-1] + a[i];
        }

        for (i = 1; i <= c; i++)
        {
            s[i] = (sum[i] + 10) * p[i];
            for (j = 1; j < i; j++)
            {
                s[i] = min(s[j] + (sum[i] - sum[j] + 10) * p[i], s[i]);
            }
        }
        //out(s + 1, c);
        cout << s[c] << endl;
    }
    return 0;
}
