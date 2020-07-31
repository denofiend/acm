#include <iostream>
#define R 3.1415
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		double x , y ,s = 0;
		cin >> x >> y;
		s = R * ((x * x) + (y * y));
		cout << "Property" << i << ": This property will begin eroding in year " << (int)(s / 100 + 1) << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}