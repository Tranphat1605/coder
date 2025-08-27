#include <bits/stdc++.h>

using namespace std;
int n, k;
int a[10006];
bool constrain = false;

void init(){
    for (int i = 0 ; i < n ; i++){
        if( i != n - 1) a[i] = 1;
        else a[i] = k - n + 1;
    }
}
void generation(){
    while(constrain == false){
        for (int i = 0 ;i < n ; i++){
        cout << a[i] << ' ';
        }
        cout << endl;
        int i = n - 1;
        while(i >= 1 && a[i] == 1){
            i--;
        }
        if(i){
            a[i]--;
            a[i - 1]++;
        }
        else constrain = true;
    }
}
int main(){
    cin >> n >> k;
    init();
    generation();

    return 0;
}