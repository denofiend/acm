// 1226(pku)

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 100
using namespace std;
bool check( const string str[MAX], const string substr, const string revsubstr, const int str_num ){
	int str_ids;
	for ( str_ids = 0; str_ids < str_num; str_ids ++ )
		if ( string::npos == str[str_ids] .find( substr ) && string::npos == str[str_ids].find( revsubstr) )
			return false;
	return true;
}
int main(){
	string str[MAX];
	int testcase;
	cin >> testcase;
	
	while ( testcase -- )
	{
		/* the number of str, the longest length of subseq, and the index of str */
		int str_num, longest = 0, str_ids, str_ids1, str_ids2;
		cin >> str_num;

		/* input the string */
		string input;
		bool ok ;
		for ( str_ids = 0, str_ids2 = 0; str_ids < str_num; str_ids ++ )
		{
			ok = false;
			cin >> input;
			for ( str_ids1 = 0; str_ids1 < str_ids && !ok; str_ids1 ++ )
				if ( str[ str_ids1] == input )
					ok = true;
			if ( !ok )
				str[ str_ids2 ++ ] = input;
		}
		/* the str_ids2 to record the number of string in str[] */
		str_num = str_ids2;

		string::size_type len;
		string::size_type size;
		map<string, bool> flag;
		int num = 0;
		for ( str_ids = 0; str_ids < str_num; str_ids ++ )
		{
			size = str[ str_ids ].size();
			for ( len = size; len; len -- )
				for ( string::size_type ids = 0; ids + len <= size; ids ++ )
				{
					string substr( str[ str_ids ].substr( ids, len ) );
					if ( !flag[ substr ] )
					{
						flag[ substr ] = true;
						string revsubstr( substr );
						reverse( revsubstr.begin(), revsubstr.end());
						if ( check( str, substr,  revsubstr, str_num ) )
						{
							if ( longest < substr.size() )
								longest = substr.size();
						}
					}
				}
		}
		cout << longest << endl;
	}
	return 0;
}