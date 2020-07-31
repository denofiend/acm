//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int num[30];

string process(string str){
	int i, n = (int)str.size(), m, pos;
	for (i = 0; i <= 9; i ++)	num[i] = 0;
	for (i = 0; i < n; i ++)
	{
		pos = str[i] - '0';
		num[pos] ++;
	}

	string ret;
	for (i = 0; i <= 9; i ++)
	{
		if (0 == num[i])	continue;

		m = num[i];
		if (m > 10)
		{
			ret += m / 10 + '0';
			m %= 10;
		}
		ret += m + '0';
		ret += i + ' 0';
	}
	return ret;
}

int main(){
	string input;
	while (cin >> input)
	{
		
		if ('-' == input[0])	break;
		//cout << input << endl;
		string inventory = process(input);
		if (inventory == input)	cout << input << " is self-inventorying" << endl;
		else
		{
			int k, i;
			bool flag;
			vector<string> tmp;
			tmp.push_back(input);
			//cout << "temp: " << temp << endl;
			for (k = 1; k <= 15; k ++)
			{
				inventory = process(tmp[k - 1]);
				//cout << tmp[k - 1] << endl;

				if (inventory == tmp[k - 1])
				{
					cout << input << " is self-inventorying after " << k - 1 << " steps" << endl;
					break;
				}
				flag = false;
				for (i = k - 2; i >= 0; i --)
					if (tmp[i] == inventory)
					{
						cout << input << " enters an inventory loop of length " << k - i << endl;
						flag = true;
					}
				if (flag)	break;

				tmp.push_back(inventory);
			}
			if (k > 15)	cout << input << " can not be classified after 15 iterations" << endl;
		}
	}
	return 0;
}