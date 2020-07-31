#include <iostream>
using namespace std;

int main(){
	int n , m;
	while( cin >> n >> m)
	{
		bool flag = false;
		if( n > m )
		{
			swap(n,m);
			flag = true;
		}
		int num = 1;
		for(int i = n;i <= m;i ++)
		{
			int num1 = 1;
			int t = i;
			while(t != 1)
			{
				if(t % 2 == 0)
					t /= 2;
				else
					t = 3 * t + 1;
				num1 ++;
			}
			if(num1 > num)
				num = num1;
		}
		if(!flag)	
			cout << n << " " << m << " " << num << endl;
		else
			cout << m << " " << n<< " "  << num << endl;
	}
	return 0;
}
