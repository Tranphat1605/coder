#include <iostream>
#include <math.h>
 
using namespace std;
 
int N;
 
string decToBin(int n){
    string ans = "";
    while (n > 0) {
        ans = char (n % 2 + '0') + ans;
        n /= 2;
    }
    while (ans.length() < N)
        ans = "0" + ans;
    return ans;
}
 
int main(){
    cin >> N;
    int d = 0; 
    int N_2 = pow(2, N);
    for (int i = 0; i < N_2; i++) {
    	decToBin(i); 
    	d++;
        cout <<i << " "<< decToBin(i) << endl;
    }
    cout << "So he nhi phan la: " << d;
}