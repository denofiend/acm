//

#include <iostream>
#include <math.h>
using namespace std;


int main(){
    int N, K;
    while (cin >> N >> K)
    {
        int Si, Ti, Ri, time, nn, t;
        while (K --)
        {
            cin >> Si >> Ti >> Ri;

            time = 0;
            nn = 0;

            while (nn < N)
            {
                t = (int)ceil((N - nn) / (double)Si);
                //printf("t = %d\n", t);
                if (0 == t)
                {
                    time ++;
                    break;
                }
                else if (t <= Ti)
                {
                    time += t;
                    nn += t * Si;
                    break;
                }
                else
                {
                    time += Ti;
                    nn += Ti * Si;
                }
                time += Ri;
            }
            cout << time << endl;
        }
    }
    return 0;
}
