#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    bool hoa = false, thuong = false, so = false;

    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) hoa = true;
        if (islower(s[i])) thuong = true;
        if (isdigit(s[i])) so = true;
    }

    if (hoa && thuong && so && s.length() > 7) {
        cout << "STRONG";
    } else {
        cout << "WEAK";
    }

    return 0;
}

