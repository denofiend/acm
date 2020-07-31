// 3639(pku)
//


#include <stdio.h>
#include <math.h>

int main() {
    int     N;
    double  X,  Y,  R;
    while (scanf("%d", &N) && N)
    {
        //
        X = 1000.0;
        Y = 0.0;
        while (N--)
        {
            scanf("%lf", &R);

            Y = Y >= int(100.0 * X / R * 0.97) / 100.0 ? Y : int (100.0 * X / R * 0.97) / 100.0;
            X = X >= int(100.0 * Y * R * 0.97) / 100.0 ? X : int (100.0 * Y * R * 0.97) / 100.0;
        }
        printf("%.2f\n", X);
    }
}
