#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		float x , y ,s = 0, R = 3.14159;
		cin >> x >> y;
		s = R * ((x * x) + (y * y));
		cout << s << endl;
		cout << "Property" << i << ": This property will begin eroding in year " << (int)(s / 100.00 + 1)  << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}