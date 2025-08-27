#include <iostream> 
#include <cmath>

using namespace std;

int main () {
	string s;
	int sum = 0;
	getline (cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) {
			sum += s[i] - '0' ;
		} 
	}
	cout << sum;
	return 0;
}
