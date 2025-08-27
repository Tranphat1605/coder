#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[10006];

void Try(int i, int start){
    if(i == k){
        for (int j = 0 ; j < i ; j++){
            cout << a[j] << ' ';
        }
        cout << endl;
        return;
    }
    for (int j = start ; j <= n ; j++){
        a[i] = j;
        Try(i + 1, j + 1);
    }
}
int main(){
    cin >> n >> k;

    Try(0, 1);
}