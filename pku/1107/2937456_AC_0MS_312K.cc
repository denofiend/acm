// zab08
// 2819(poj)

#include <iostream>
#include <string>
using namespace std;

void rotated( string & str1, const int str_size, const int k ){
	string str( str1 );
	int str_ids = 0;
	// very import equation (str_ids + k ) % str_size
	for ( str_ids = 0; str_ids < str_size; str_ids ++ )
		str1[ (str_ids + k ) % str_size] = str[ str_ids ];
}
int main(){
	int k1, k2, k3;
	while ( cin >> k1 >> k2 >> k3 )
	{
		if ( 0 == k1 && 0 == k2 && 0 == k3 )
			break;
		string str, str1, str2, str3;
		cin >> str;
		// filled up the three group from the input string str
		int str_ids, str_size = str.size();;
		for ( str_ids = 0; str_ids < str_size; ++ str_ids )
		{
			if ( 'a' <= str[ str_ids ] && 'i' >= str[ str_ids ] )
				str1 += str[ str_ids ];
			else if ( 'j' <= str[ str_ids ] && 'r' >= str[ str_ids ] )
				str2 += str[ str_ids ];
			else
				str3 += str[ str_ids ];
		}
		int str1_size = str1.size(), str2_size = str2.size(), str3_size = str3.size();
		// rotated the three group respectily
		rotated(str1, str1_size, k1);
		rotated(str2, str2_size, k2);
		rotated(str3, str3_size, k3);
		int str1_ids = 0, str2_ids = 0, str3_ids = 0;
		// output the answer
		for ( str_ids = 0; str_ids < str_size; ++ str_ids )
		{
			if ( 'a' <= str[ str_ids ] && 'i' >= str[ str_ids ] )
				str[ str_ids ] = str1[ str1_ids ++];
			else if ( 'j' <= str[ str_ids ] && 'r' >= str[ str_ids ] )
				str[ str_ids ] = str2[ str2_ids ++ ];
			else
				str[ str_ids ] = str3[ str3_ids ++ ];
		}
		cout << str << endl;
	}
	return 0;
}