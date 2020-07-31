

#include <iostream>
#include <algorithm>
using namespace std;

bool used[64];
bool ok;
int stick[64];
int n;
int len;
int ns;
int total;

bool cmp(const int a1, const int a2){
	return a1 > a2;
}

// num表示当前还原第n个棍子
// now表示还原第num个棍子还需要now长度的短棍
// pos表示处于当前短棍中的位置
int search(int num, int now, int pos){
	bool flag = false;
	if (now == len) flag = true;

	//
	if (num == total / len)
	{
		ok = true;
		return 1;
	}

	for (int i = pos; i <= n; i ++)
	{
        if (!used[i])
		{
			if (stick[i] < now)
			{
				used[i] = true;
				if (search(num, now - stick[i], i + 1)) return 1;
				used[i] = false;
				if (flag) return 0;
			}
			else if (stick[i] == now)
			{
				used[i] = true;
				if(search(num + 1, len, 1)) return 1;
				used[i] = false;
				return 0;
			}
			else if(flag) return 0;
		}
	}
    return 0;
}

int main(){
	while (cin >> n)
	{
		ok = false;
		ns = 0;
		if(!n)
			break;
		total = 0;
		for (int j = 1; j <= n; j ++)
		{
			cin >> stick[j];
			total += stick[j];
		}
		sort(stick + 1, stick + n + 1, cmp);

		for (int i = stick[1]; i <= total; i ++)
		{
			if (ok) break;
			if (0 == total % i)
			{
				ns = total / i;
				len = i;
				memset(used, false, sizeof(used));

				if (search(1, len, 1))
					cout << len << endl;
			}
		}
	}
	return 0;
}

