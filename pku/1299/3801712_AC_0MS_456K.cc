//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main(){
	string input;
	int x, y, z;
	const double PI = acos(-1);
	while (cin >> input)
	{
		if ("ENDOFINPUT" == input)	break;
		
		cin >> x >> y >> z;
		z %= 360;
		double d = x * (z * PI / 180);
		double fee = d * 0.4;
		//cout << "fee: " << fee << "  d: " << d << endl;
		if (fee <= y)
		{
			cout << "YES " << (int)(y - fee) << endl;
		}	
		else
		{
			cout << "NO " << (int)(y * 5) << endl;
		}
		cin >> input;
	}
	return 0;
}