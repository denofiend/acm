//

#include <iostream>

using namespace std;


int main(){
    double k, p;
    while (EOF != scanf("%lf", &k))
    {
        if (0.0 == k)   break;
        scanf("%lf", &p);

        double ans = k / p;
        double ans1 = (k + 1) * ans / p - ans;
        printf("%.3lf %.3lf\n", ans, ans1);
    }
    return 0;
}
