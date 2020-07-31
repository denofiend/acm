// 1028(pku)

#include <iostream>
#include <string>
#include <stack>

using namespace std ;

string commond, url ;
stack<string> back, forward ;

int main(){
	url = "http://www.acm.org/" ;
	while( cin >> commond )
	{
		if( "QUIT" == commond )
			break ;
		else if( "VISIT" == commond )
		{
			while( ! forward.empty() )
				forward.pop() ;
			back.push(url) ;
			cin >> url ;
			cout << url << endl ;
		}
		else if( "BACK" == commond )
		{
			if( back.empty() )
				cout << "Ignored" << endl ;
			else
			{
				forward.push( url ) ;
				url = back.top() ;
				back.pop() ;
				cout << url << endl ;
			}
		}
		else if( "FORWARD" == commond )
		{
			if( forward.empty() )
				cout << "Ignored" << endl ;
			else
			{
				back.push( url ) ;
				url = forward.top() ;
				forward.pop() ;
				cout << url << endl ;
			}
		}
	}
	return 0 ;
}