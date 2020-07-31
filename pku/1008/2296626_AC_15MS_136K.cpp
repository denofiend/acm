//===========
// 1008 pku
// 用了STL的map
//-----------
#include <iostream>
#include <string>
#include <map>
using namespace std ;
int main(){
	
	map<string, int> Haab;
	Haab["pop"] = 0 , Haab["no"] = 1 , Haab["zip"] = 2 ,Haab["zotz"] = 3 , Haab["tzec"] = 4 , Haab["xul"] = 5 ;
	Haab["yoxkin"] = 6 ,Haab["mol"] = 7 ,Haab["chen"] = 8 ,	Haab["yax"] = 9 ,Haab["zac"] = 10 ,	Haab["ceh"] = 11 ;
	Haab["mac"] = 12 ,Haab["kankin"] = 13 ,	Haab["muan"] = 14 ,	Haab["pax"] = 15 , Haab["koyab"] = 16 ,Haab["cumhu"] = 17 , Haab["uayet"] = 18 ;

	map<int,string> Tzolkin ;
	Tzolkin[0] = "imix" , Tzolkin[1] = "ik" ,Tzolkin[2] = "akbal", Tzolkin[3] = "kan", Tzolkin[4] = "chicchan", Tzolkin[5] = "cimi", Tzolkin[6] = "manik" ;
	Tzolkin[7] = "lamat" ,Tzolkin[8] = "muluk", Tzolkin[9] = "ok", Tzolkin[10] = "chuen", Tzolkin[11] = "eb", Tzolkin[12] = "ben" ;
	Tzolkin[13] = "ix" , Tzolkin[14] = "mem", Tzolkin[15] = "cib", Tzolkin[16] = "caban", Tzolkin[17] = "eznab", Tzolkin[18] = "canac" ,Tzolkin[19] = "ahau" ;
	int n  ;
	cin >> n ;
	cout << n << endl ;
	int day , year , totaldays = 0 ;
	string month ;
	map<string, int>::iterator pos ;
	map<int,string>::iterator pos1 ;
	while( n -- )
	{
		cin >> day ;
		cin.ignore() ;
		cin >> month >> year ;
		
		pos = Haab.find(month) ;
		totaldays = day + 20 * ( pos ->second ) + year * 365 ;

		pos1 = Tzolkin.find( totaldays % 20 ) ;

		cout << 1 + totaldays % 13 << " " << pos1 -> second << " " << totaldays / 260 << endl ;
	}
	
	return 0 ;
}
