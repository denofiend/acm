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

		double ans = x * (z * PI / 180);
		double fee = ans * 0.4;
		//cout << "fee: " << fee << "  ans: " << ans << endl;
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