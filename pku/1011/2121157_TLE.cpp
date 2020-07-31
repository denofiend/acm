#include <iostream>
#include <algorithm>
using namespace std;

int stick[64];
bool used[64];
int n;
bool ok;
int ns;

void s(int len){
	while(ns)
	{
		int now = 0;
		for(int i = n;i > 0;i --)
		{
			if(!used[i] && now +stick[i] <= len)
			{
					now += stick[i];
					used[i] = true;
			}
			if(now ==len)
			{
				ns --;
				break;
			}
		}
	}
	if(ns == 0)
	{
		ok = true;
		cout << len;
	}
}
int main(){
	while(cin >> n){

		ok = false;
		ns = 0;
		if(!n)
			break;

		int total= 0, max= 0;
		for(int j = 1;j <= n;j ++)
		{
			cin >> stick[j];
			total += stick[j];
			if(stick[j] > max)
				max = stick[j];
		}
		sort(stick + 1,stick + n + 1);
		for(int i = max;i <= total;i ++)
		{
			if(ok)break;
			if(total % i == 0 && !ok)
			{
				ns = total / i;
				memset(used,false,sizeof(used));
				s(i);
			}
		}	
	}
	return 0;
}
