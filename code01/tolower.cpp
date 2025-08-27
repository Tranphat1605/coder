#include<iostream> 
#include<cmath>

using namespace std;

void lower(string *s) {
	for (int i = 0; i < s->length();  i++) {
		(*s)[i] = tolower((*s)[i]);
	}
} 

int main () {
	string s;
	getline(cin, s);
	lower(&s);
	cout << s;
	return 0;
}
