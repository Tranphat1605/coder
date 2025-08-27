#include <bits/stdc++.h>

using namespace std;

int n;
int a[100006];
bool constrain = false;
void init(){
    for (int i = 0 ; i < n ; i++){
        a[i] = i + 1;
    }
}

void generation(){
    while (constrain == false){
        for (int i = 0 ; i < n ; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        int i = n - 2;
        while(i >= 0 && a[i] > a[i + 1]){
            i--;
        }
        if(i != -1){
            for(int j = n - 1; j >= i + 1; j--){
                if(a[j] > a[i]){
                    swap(a[j], a[i]);
                    reverse(a + i + 1, a + n);
                    break;
                }
            }
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