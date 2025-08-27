#include <bits/stdc++.h>

using namespace std;

char c[] = {'a', 'b', 'c', 'd', 'e', 'f'};
int a[10006];
bool constrain = false;
int cnt = 1;

void init(){
    for (int i = 0 ; i <= 5 ; i++){
        a[i] = 0;
    }
}

void generation(){
    while(constrain == false){
        cout << cnt << ". ";
        cnt++;
        for (int i = 0 ; i < 6 ; i++){
            if(a[i]){
                cout << c[i] << ' ';
            }
        }
        cout << endl;
        int i = 5;
        while(i >= 0 && a[i] == 1){
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
    init();
    generation();

    return 0;
}