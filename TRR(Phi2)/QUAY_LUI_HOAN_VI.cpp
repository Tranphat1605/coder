#include <bits/stdc++.h>

using namespace std;

int n;
int a[10006];
int used[10006];

void Try(int i){
    if(i == n){
        for (int j = 0 ; j < n ; j++){
            cout << a[j] << ' ';
        }
        cout << endl; 
        return ;
    }
    for (int j = 1 ; j <= n ; j++){
        if(!used[j]){
            used[j] = 1;
            a[i] = j;
            Try(i + 1);
            used[j] = 0;
        }
    }
}
int main(){
    cin >> n;

    Try(0);

    return 0;
}