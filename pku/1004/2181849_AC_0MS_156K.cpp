#include <iostream>
using namespace std;

int main(){
	float num[12],sum = 0,average;
	for(int i = 0;i < 12;++ i)
		cin >> num[i];
	for(int j = 0;j < 12; ++ j)
		sum += num[j];
	average = sum / 12;
	cout << "$" << average << endl;
	return 0;
}