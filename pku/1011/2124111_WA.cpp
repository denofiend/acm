#include <iostream>
#include <algorithm>
using namespace std;

bool used[100];
bool ok;
int stick[100];
int n;
int len;
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

int search(int num,int now,int pos){
	if(num == total / len)
	{
		ok = true;
		return 1;
	}

	for(int i = pos;i <= n;i ++)
		if(!used[i])
		{
			if(stick[i] < now)
			{
				used[i] = true;
				if(search(num,now - stick[i],i +1))return 1;
				used[i] = false;
			}
			else if(stick[i] == now)
			{
				used[i] = true;
				if(search(num + 1,len,1)) return 1;
			}

		}
		return 0;
}
int main(){
	while(cin >> n){
		ok = false;
		ns = 0;
		if(!n)
			break;
		for(int j = 1;j <= n;j ++)
			cin >> stick[j];
		total = add();
		sort(stick + 1,stick + n + 1,greater);
		for(int i = stick[1];i <= total;i ++)
		{
			if(ok)break;
			if(total % i == 0)
			{
				ns = total / i;
				len = i;
				memset(used,false,sizeof(used));
				if(search(1,len,1))
					cout << len << endl;
			}
		}	
	}
	return 0;
}
