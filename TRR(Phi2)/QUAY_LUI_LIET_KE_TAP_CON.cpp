#include <bits/stdc++.h>

using namespace std;

char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
int ans[1000006];
int cnt = 1;

void Try(int i){
    if(i == 6){
        cout << cnt << ". ";
        cnt++;
        for (int j = 0 ; j < 6 ; j++){
            if(ans[j]){
                cout << a[j] << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int j = 0 ; j <= 1; j++){
        ans[i] = j;
        Try(i + 1);
    }
}

int main(){
    Try(0);

    return 0;
}