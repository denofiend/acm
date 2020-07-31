//

#include <iostream>

using namespace std;

int main(){
    int n;
    while (cin >> n)
    {
        if (0 == n % 2)
        {
            cout <<  n / 2 - 1 << ' ' << n / 2 + 1 << endl;
        }
        else
        {
            cout << n / 2  << ' ' << n / 2 + 1 << endl;
        }
    }
    return 0;
}
