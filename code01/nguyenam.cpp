#include <iostream> 
#include <cmath>

using namespace std;

int main () {
	string s;
	int t = 0;
	getline (cin, s);
	for (int i = 0; i < s.length(); i++ ) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
			t++;
		}
	}
	cout << t;
	return 0;
} 
