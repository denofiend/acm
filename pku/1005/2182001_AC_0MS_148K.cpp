#include <iostream>
using namespace std;
int main(){
	int n;
	float x = 0.0, y = 0.0 ,s = 0.0, R = 3.1415926;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		cin >> x >> y;
		s = R * (x * x + y * y);
		cout << "Property " << i << ": This property will begin eroding in year " << (int)(s / 100.0 + 1) << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}