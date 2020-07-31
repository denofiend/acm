//

#include <iostream>
#define Max_N 50000
#define Max_P 52000
#define _int64 long long

using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i++)	out(x[i], m);	cout << endl;	}

_int64 Prime[Max_N];//对素数的标记
_int64 P_div[Max_P];//存储素数约数
_int64 P_mi[Max_P];//存储素数约数的幂

//筛选素数
void init(){
	_int64 i, j;
	Prime[1] = 1;
	for (i = 2; i < Max_N; i++)
		if (!Prime[i])
			for (j = 2; j * i < Max_N; j++) 
				Prime[j * i] = 1;
}


//整数因子分解
int factorization(int n){
	//printf("n = %d\n", n);
	int i, j = 0;
	for (i = 2; i < Max_N && n > 1; i ++)
	{
		if (!Prime[i] && 0 == n % i)
		{
			P_div[j] = i;
			P_mi[j] = 0;
			while (0 == n % i)
			{
				++P_mi[j];
				n /= i;
			}
			j ++;
		}
		//printf("[%d %d]\n", n, j);
	}

	if (i >= Max_N || !j)
	{
		P_div[j] = n;
		P_mi[j++] = 1;
	}
	
	//cout << "----------------" << endl;
	//out(P_div, j);
	//out(P_mi, j);
	return j;
}



bool ok(int n){
	int sum1 = 0, sum2 = 0, i, j, nn, t;
	i = n;
	while (i)
	{
		sum1 += i % 10;
		i /= 10;
	}

	j = factorization(n);

	//printf("j = %d\n", j);
	for (i = 0; i < j; i ++)
	{		
		
		nn = P_div[i];
		//printf("nn = %d\n", nn);
		t = 0;
		while (nn)
		{
			t += nn % 10;
			nn /= 10;
		}
		sum2 += t * P_mi[i];
	}
	if (sum1 == sum2)	return true;
	else return false;
}

int main(){
	int n, i;
	init();
	while (EOF != scanf("%d", &n))
	{
		if (0 == n)	break;
		for (i = n; ; i ++)
			if (ok(i))	
			{
				printf("%d\n", i);
				break;
			}

	}
	return 0;
}