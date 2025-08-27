#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[1000006];
bool constrain = false;

void init(){
    for (int i = 0 ; i < k ; i++){
        a[i] = i + 1;
    }
}

void generation(){
    while(constrain == false){
        for (int i = 0 ; i < k ; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        int i = k - 1;
        while(i >= 0 && a[i] == n - k + i + 1){
            i--;
        }
        if(i != -1){
            a[i]++;
            for (int j = i + 1 ; j < k ; j++){
                a[j] = a[j - 1] + 1;
            }
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