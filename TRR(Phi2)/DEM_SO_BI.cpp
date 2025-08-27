#include <bits/stdc++.h>

using namespace std;

int a[10000006];
int cnt = 0;

bool check(){
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0 ; i < 12 ; i++){
        if(a[i] == 1) cnt1++;
        else if(a[i] == 0) cnt2++;
    }
    for (int i = 1 ; i < 12 ; i++){
        if(a[i] == a[i - 1]) return false;
    }
    return cnt1 == cnt2 && cnt2 == 4;
}

void Try(int i){
    if(i == 12){
        if(check()){
            for (int j = 0 ; j < 12 ; j++){
                cout << a[j] << ' ';
            }
            cout << endl;
            cnt++;
        }
        return;
    }
    for (int j = 0 ; j < 3 ; j++){
        a[i] = j;
        Try(i + 1);
    }
}
int main(){
    Try(0);

    cout << cnt;

    return 0;
}