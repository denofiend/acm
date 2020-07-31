#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t --)
	{
		int n , p, son;
		cin >> n;
		int *pe = new int[n + 1];
		int *path1 = new int[n + 1];
		int *path2 = new int[n + 1];
		for(int i = 1;i <= n;i ++)
			pe[i] = i;
		for(int j = 1;j < n;j ++)
		{
			cin >> p >> son;
			pe[son] = p;
			path1[j] = 0;
			path2[j] = 0;
		}
		path1[n] = 0;
		path2[n] = 0;
		int note1,note2,flag = false;
		cin >> note1 >> note2;
		path1[1] = note1;
		path2[1] = note2;
		for(int d = 2;d <= n;d ++)
		{
			path1[d] = pe[ path1[d - 1] ];
			path2[d] = pe[ path2[d - 1] ];
		}
		for(int k = 1;k <= n && !flag;k ++)
			for(int u = 1;u <= n;u ++)
				if(path1[k] == path2[u])
				{
					cout << path1[k] << endl;
					flag = true;
					break;
				}
	}
	return 0;
}