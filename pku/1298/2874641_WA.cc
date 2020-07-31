// 1298(pku)

#include <iostream>
#include <string>

using namespace std;


int main(){
	string str;
	while ( getline( cin, str ) )
	{
		getline( cin, str );
		int str_num = str.size(), str_ids;
		for ( str_ids = 0; str_ids < str_num; ++ str_ids )
		{
			if ( 'E' <= str[ str_ids ] && 'Z' >= str[ str_ids] )
				cout << char ( ( str[ str_ids ] - 5  - 65 ) % 26 + 65 );
			else if ( 'A' <= str[ str_ids ] && 'E' > str[ str_ids ] )
				cout << char ('Z' - ( 4 - str[ str_ids ] + 'A') );
			else
				cout << str[ str_ids ];
		}
		cout << endl;
		getline( cin, str );
	}
	return 0;
}