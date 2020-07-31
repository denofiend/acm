//

#include <iostream>
#include <string>
using namespace std;


string output(char c){
	string ret;
	if (' ' == c)
	{
		ret += "%20";
	}
	else if ('!' == c)
	{
		ret += "%21";
	}
	else if ('$' == c)
	{
		ret += "%24";
	}
	else if ('%' == c)
	{
		ret += "%25";
	}
	else if ('(' == c)
	{
		ret += "%28";
	}
	else if (')' == c)
	{
		ret += "%29";
	}
	else if('*' == c)
	{
		ret += "%2a";
	}
	else 
	{
		ret += c;
	}
	return ret;
}


int main(){
	string mess;
	while (getline(cin, mess))
	{
		if ('#' == mess[0])	break;
		int n = mess.size();
		for (int i = 0; i < n; i ++)
		{
			cout << output(mess[i]);
		}
		cout << endl;
	}
	return 0;
}