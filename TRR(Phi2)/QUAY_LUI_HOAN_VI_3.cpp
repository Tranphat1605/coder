#include <bits/stdc++.h>

using namespace std;

char a[] = {'a', 'b' , 'c', 'd', 'e', 'f'};
char ans[100006];
char used[100006];
int cnt = 1; 

void Try(int i){
    if(i == 3){
        cout << cnt << ". ";
        cnt++;
        for (int j = 0 ; j < 3 ; j++ ){
            cout << ans[j] << " ";
        }
        cout << endl;
        return;
    }
    for (int j = 0 ; j < 6 ; j++){
        if(!used[a[j]]){
            ans[i] = a[j];
            used[a[j]] = 1;
            Try(i + 1);
            used[a[j]] = 0;
        }
    }
}
int main(){
    Try(0);

    return 0;
}