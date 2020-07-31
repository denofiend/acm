//

#include <iostream>
#include <string.h>
#define MAXN 1000
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i  < n; i ++)	out(x[i] , m);	cout << endl;	}

int path[MAXN];
int sum, i, num, sum1, cnt;
char c;

int main(){
	cnt = sum = sum1 = num = 0;
	while (cin >> sum)
	{
		memset(path, 0, sizeof(path));
		while (cin >> c)
		{
			if (')' == c)
			{	
				//printf("[%d %d %d]\n", i, path[i + 1], num);
				//printf("<%d %d>\n", sum1, sum);				
				//out(path, i);
				i --;
				if (2 == num)
				{	
					if (sum1 == sum)
					{
						cnt++;
					}
					num = 0;
				}
				sum1 -= path[i + 1];
				path[i + 1] = 0;

				if (0 == i)
				{
					if (cnt >= 1)
						cout << "yes" << endl;
					else cout << "no" << endl;
					num = sum1 = sum = cnt = 0;
					break;
				}
				else
				{
					continue;
				}
			}
			else if ('(' == c)
			{
				i ++;
				num ++;
			}
			else 
			{
				num = 0;
				if ('-' == c)
				{
					while (cin >> c)
					{
						if (!isdigit(c))
							break;
						path[i] = path[i] * 10 + c - '0';
					}					
					path[i] = -path[i];
				}
				else 
				{
					while (1)
					{
						path[i] = path[i] * 10 + c - '0';
						cin >> c;
						if (!isdigit(c))
							break;
					}
				}
				sum1 += path[i];
				if ('(' == c)
				{
					i++;
					num++;
				}
			}
		}
	}
	return 0;
}