//

#include <iostream>

using namespace std;


int main(){
	int M, T, U, F, D;
	while (cin >> M >> T >> U >> F >> D)
	{
		char c, totalTime = 0;
		int i;
		for (i = 1; i <= T; i ++)
		{
			cin >> c;
			if ('u' == c)
			{
				totalTime += U + D;
			}
			else if ('f' == c)
			{
				totalTime += F + F;
			}
			else if ('d' == c)
			{
				totalTime += D + U;
			}
			if (totalTime > M)	break;
		}
		printf("%d\n", i - 1);
		while (i < T)	
		{	
			cin >> c;
			i ++;
		}
	}
	return 0;
}