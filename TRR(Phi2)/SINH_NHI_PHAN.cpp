#include <bits/stdc++.h>

using namespace std;
int a[10006];
int n;
bool constrain = false;

void init(){
    for (int i = 0 ; i < n ; i++){
        a[i] = 0;
    }
}

void generation(){
    while(constrain == false){
        for (int i = 0 ; i < n ; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        int i = n - 1;
        while( i >= 0 && a[i] == 1){
            a[i] = 0;
            i--;
        }
        if(i != -1){
            a[i] = 1;
        }
        else constrain = true;
    }
}

int main(){
    cin >> n;

    init();
    generation();

    return 0;
}