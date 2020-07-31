//

#include <iostream>

using namespace std;

char str[100001];

int main(){
	int M, T, U, F, D;
	while (cin >> M >> T >> U >> F >> D)
	{
		int totalTime = 0;
		int i;
		for (i = 1; i <= T; i ++)
		{
			cin >> str[i];
		}
		for (i = 1; i <= T; i ++)
		{
			if ('u' == str[i])
			{
				totalTime += U + D;
			}
			else if ('f' == str[i])
			{
				totalTime += F + F;
			}
			else if ('d' == str[i])
			{
				totalTime += D + U;
			}
			if (totalTime > M)	break;
		}
		printf("%d\n", i - 1);
	}
	return 0;
}