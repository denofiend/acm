
#include <iostream>
using namespace std;

#define NMAX 150000
#define INFI 99999999
#define CMAX 11

int flag[NMAX];
int lleft[NMAX];
int cashm[CMAX];
int cashn[CMAX];

void solve(int n, int cash){
	int i, j;
	memset(flag, 0, sizeof(flag));
	flag[0] = 1;
	for (i = 1; i <= n; i ++)
	{
	    memset(lleft, 0, sizeof(int) * cash);
	    for (j = 0; j <= cash; j ++)
	    {
	        if (1 == flag[j])   lleft[j] = cashn[i];
	    }
	    for (j = 0; j <= cash; j ++)
	    {
	        if (lleft[j] > 0)
	        {
	            flag[j + cashm[i]] = 1;
	            lleft[j + cashm[i]] = max(lleft[j] - 1, lleft[j + cashm[i]]);
	        }
	    }
	}
    for (i = cash; i >= 0; i --)
    {
        if (1 == flag[i]){  printf("%d\n", i);  break;}
    }
}

int main(){
	int i, cash, n;
	while (EOF != scanf("%d %d", &cash, &n))
	{
	    for (i = 1; i <= n; i ++)   scanf("%d %d", &cashn[i], &cashm[i]);
		solve(n, cash);
	}
	return 0;
}
