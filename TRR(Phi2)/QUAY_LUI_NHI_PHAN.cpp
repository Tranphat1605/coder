#include <bits/stdc++.h>

using namespace std;

int n;
int a[100006];

void Try(int i){
    if(i == n){
        for (int j = 0 ; j < n ; j++){
            cout << a[j] << ' ';
        }
        cout << endl;
        return;
    }
    a[i] = 0;
    Try(i + 1);
    a[i] = 1;
    Try(i + 1);
}

int main(){
    cin >> n;

    Try(0);

    return 0;
}