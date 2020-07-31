#include <iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n)
	{

		if(!n)break;
		int * stack = new int[n + 1];
		memset(stack,0,n + 1);
		int pos = 1,top = 0,num = 0,now;
		while(cin >> now)
		{
			if(!now)
			{
				cout << endl;
				break;
			}
			num ++;
			while(pos <= n && now != stack[top])
			{	
				top ++;
				stack[top] = pos ++;
			}
			if(now == stack[top])
					top --;
			if(top == 0)
			{
				if(num == n)
				{	    
					pos = 1;
		    		top = 0;
			    	num = 0;
				    cout << "Yes" << endl;
				}
			}
			else if(num == n)
			{
				pos = 1;
				top = 0;
				num = 0;
				cout << "No" << endl;
			}
		}
	}
	return 0;
}