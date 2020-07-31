// 1298(pku)

#include <iostream>
#include <string>

using namespace std;


int main(){
	string str;
	while ( getline( cin, str ) )
	{
		if ( "START" == str )
		{
			getline( cin, str );			
			int str_num = str.size(), str_ids;
			for ( str_ids = 0; str_ids < str_num; ++ str_ids )
			{
				if ( 'A' <= str[ str_ids ] && 'Z' >= str[ str_ids]  )
					cout << char ( ( str[ str_ids ] - 5 - 65 + 26 ) % 26 + 'A' );
				else
					cout << str[ str_ids ];
			}
			cout << endl;
		}
		else if ( "ENDOFINPUT" == str )
			break;
		getline( cin, str );
	}
	return 0;
}