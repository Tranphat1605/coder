#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int res = n;
    int i;
    for (i = 2; i <= (n / 2); i++)
    {
        int dem = 0;
        if (res % i == 0)
        {
            while (res % i == 0)
            {
                res /= i;
                dem++;
            }
            cout << i;
            if (dem > 1)
                cout << "^" << dem;
            break;
        }
    }

    for (int j = i; j <= (n / 2); j++)
    {
        int dem = 0;
        if (res % j == 0)
        {
            cout << "*";
            while (res % j == 0)
            {
                res /= j;
                dem++;
            }
            cout << j;
            if (dem > 1)
                cout << "^" << dem;
        }
    }
}