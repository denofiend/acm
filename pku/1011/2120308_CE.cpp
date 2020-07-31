#include <iostream>
#include <algorithm>
using namespace std;

int stick[100];
bool used[100];
int n;
bool ok;
int ns;
int total;

bool greater(const int a1,const int a2){
	return a1 > a2;
}

int add(){
	int sum = 0;
	for( int i = 1; i <= n;i ++ )
		sum += stick[i];
	return sum;
}

void s(int len){

	if(ok)return;

	while(ns)
	{
		int now = 0;
		for(int i = 1;i <= n;i ++)
		{
			if(!used[i] && now +stick[i] <= len)
			{
					now += stick[i];
					used[i] = 1;
			}
		}
		
		if(now ==len)
			ns --;
		else
			return;
	}

	if(ns == 0)
	{
		ok = 1;
		cout << len;
	}
}
int main(){
	while(cin >> n){
		for(int j = 1;j <= n;j ++)
			cin >> stick[i];
		ok = 0;
		total = add();
		sort(stick + 1,stick + n + 1,greater);
		for(int i = stick[1];i <= total;i ++)
		{
			if(total % i == 0 && !ok)
			{
				ns = total / i;
				memset(used,0,sizeof(int));
				s(i);
			}
		}

	}
	return 0;
}
