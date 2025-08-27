#include <bits/stdc++.h>

using namespace std;

int moddd(int a, int m, int n){
    int s = a % m;
    for (int i = 0; i < n - 1; i++){
        s = (s * a) % m;
    }
    return s;
}

int main(){
    int a, m, n;
    cin >> a >> m >> n;
    cout << moddd(a, n, m);
    return 0;
}
