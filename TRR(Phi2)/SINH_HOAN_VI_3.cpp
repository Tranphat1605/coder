#include <bits/stdc++.h>

using namespace std;
char c[] = {'a', 'b', 'c', 'd', 'e', 'f'};
char a[1000006];
char arr[1000006];
bool constrain = false;
bool stop = false;
int cnt = 1;

void init(){
    for (int i = 0 ; i < 3 ; i++){
        a[i] = 'a' + i;
    }
}

void generation1(){
    while(stop == false){
        constrain = false;
        for (int i = 0 ; i < 3 ; i++){
            arr[i] = a[i];
        }
        while(constrain == false){
            cout << cnt << ". ";
            cnt++;
            for (int i = 0 ; i < 3 ; i++){
                cout << arr[i] << ' ';
            }
            cout << endl; 
            int i = 1;
            while(i >= 0 && arr[i] > arr[i + 1]){
                i--;
            }
            if(i != -1){
                for (int j = 2 ; j >= i + 1 ; j--){
                    if(arr[j] > arr[i]){
                        swap(arr[j], arr[i]);
                        reverse(arr + i + 1, arr + 3);
                        break;
                    }
                }
            }
            else{
                constrain = true;
            }
        }
        int i = 2;
        while(i >= 0 && a[i] == 97 + 3 + i ){
            i--;
        }
        if( i != -1){
            a[i]++;
            for (int j = i + 1 ; j < 3 ; j++){
                a[j] = a[j - 1] + 1;
            }
        }
        else stop = true;
    }
}

int main(){
    init();
    generation1();
    return 0;
}