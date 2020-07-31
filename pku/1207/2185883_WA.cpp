#include <iostream>
using namespace std;

int main(){
	int n , m;
	while( cin >> n >> m)
	{
		if( n > m )
			swap(n,m);
		int num = 1;
		for(int i = n;i <= m;i ++)
		{
			int num1 = 1;
			int t = i;
			while(t != 1)
			{
				if(t % 2 == 0)
				{
					t /= 2;
					num1 ++;
				}
				else
				{
					t = 3 * t + 1;
					num1 ++;
				}
			}
			if(num1 > num)
				num = num1;
		}
		cout << n << " " << m << " " << num << endl;
	}
	return 0;
}
