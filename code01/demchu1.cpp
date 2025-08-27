#include <iostream>
#include <cmath>
using namespace std;

int main () {
	string s;
	getline(cin,s);
	int d = 0;
	s = " "+s;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i]==' ' && s[i+1] != ' ') {
			d++;
		}
	}
	cout << d;
	return 0;
}
