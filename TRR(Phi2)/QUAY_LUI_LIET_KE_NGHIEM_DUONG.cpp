#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100006];

void Try(int i, int sum ){
    if(i == n && sum == 0){
        for (int j = 0 ; j < n ; j++){
            cout << a[j] << ' ';
        }
        cout << endl;
        return;
    }
    for (int j = 1 ; j <= sum ; j++){
        a[i] = j;
        Try(i + 1 , sum - j);
    }
}

int main(){
    cin >> n >> k;
    Try(0, k);

    return 0;
}