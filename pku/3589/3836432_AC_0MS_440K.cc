//


#include <iostream>
#include <string>

using namespace std;


int main(){
	int t;
	string str1 ,str2;
	cin >> t;
	while (t --)
	{
		cin >> str1 >> str2;
		int n = str1.size(), m = str2.size();

		int ans1 = 0, ans2 = 0, i, j;
		for (i = 0; i < n; i ++)
		{
			for (j = 0; j < m; j ++)
			{
				if (str1[i] == str2[j] && '!' != str2[j])
				{
					if (i != j)
						ans2++;
					if (i == j)	ans1++;
					break;
					str2[j] = '!';
				}
			}
		}
		printf("%dA%dB\n", ans1, ans2);
	}
	return 0;
}