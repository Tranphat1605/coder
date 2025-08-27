#include <iostream>
#include <iomanip>
using namespace std;
int main () {
	int r;
	cout <<"Nhap ban kinh: ";
	cin >> r;
	float pi = 3.14;
	cout << fixed << setprecision(2)<< "Dien tich hinh tron: " << pi*r*r;
}