#include <bits/stdc++.h>

using namespace std;

string mahoa(string s, int k) {
    string tam;
    k = k % 26; 

    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) { 
            char kitu = (s[i] - 'A' + k) % 26 + 'A';
            tam += kitu;
        }
        else if (islower(s[i])) {
            char kitu = (s[i] - 'a' + k) % 26 + 'a';
            tam += kitu;
        } 
        else {
            tam += s[i]; 
        }
    }
    return tam; 
}

int main() {
    string s;
    getline(cin, s); 

    int k;
    cin >> k; 

    cout << mahoa(s, k); 

    return 0;
}


