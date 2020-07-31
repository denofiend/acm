// pku(1064)
// 

#include<iostream>
#define MAX 10001

using namespace std;
int main()
{
	int i, n, k, best = 0, mid, min=0;
	int max = 10000000, l[MAX];
	__int64 sum;
	double len;
	cin >> n >> k;
	for ( i = 0; i < n; ++ i )
	{
		cin >> len;
		l[i] = (int)( 100 * len );
	}
	while ( min <= max )
	{
		mid = ( min + max ) / 2;
		if( !mid )break;
		sum = 0;
		for ( i = 0; i < n; ++ i )
			sum += l[i] / mid;		
		if ( sum >=k && mid > best )
					best = mid;
		if ( sum >= k )
			min = mid + 1;
		else
			max=mid-1;	
	}
    len = double (best) / 100;
    printf("%.2lf\n", len);
    return 0 ;
}


