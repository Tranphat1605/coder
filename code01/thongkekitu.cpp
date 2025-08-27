#include <iostream> 
#include <cmath>

using namespace std;

int main () {
	string s;
	getline (cin, s);
	int A[26];
	for (int i = 0; i < 26; i++) {
		A[i] = 0;
	}
	for (int i = 0; i < s.length(); i++) {
		char c = tolower(s[i]);
		A[c - 'a']++ ;
	}
	for (int i = 0; i < 26; i++) {
		cout << A[i] << ' ';
	}
	return 0;
}
