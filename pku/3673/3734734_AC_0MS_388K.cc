//

#include <iostream>
#include <string>

using namespace std;

int main(){
	string a, b;
	while (cin >> a >> b)
	{
		int an = a.size();
		int bn = b.size();
		int i, j, ans = 0;
		for (i = an - 1; i >= 0; i --)
		{
			for (j = bn - 1; j >= 0 && i >= 0; j --)
			{
				ans += (a[i] - '0') * (b[j] - '0');
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}