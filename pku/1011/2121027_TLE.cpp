#include <iostream>
#include <algorithm>
using namespace std;

int stick[64];
bool used[64];
int n;
bool ok;
int ns;

bool greater(const int a1,const int a2){
	return a1 > a2;
}
void s(int len){
	while(ns)
	{
		int now = 0;
		for(int i = 1;i <= n;i ++)
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

		int total = 0;
		for(int j = 1;j <= n;j ++)
		{
			cin >> stick[j];
			total += stick[j];
		}

		sort(stick + 1,stick + n + 1,greater);
		for(int i = stick[1];i <= total;i ++)
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
