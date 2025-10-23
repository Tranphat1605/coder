#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}
bool isPerfect(int n)
{
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == (n / i))
                sum = sum + i;
            else
                sum = sum + (i + n / i);
        }
    }
    return (sum == n && n != 1);
}
int largestPrimeFactor(int n)
{
    int maxPrime = -1;
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n >>= 1;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
    }
    if (n > 2)
        maxPrime = n;
    return maxPrime;
}
vector<int> perfectNumbers(int M)
{
    vector<int> perfects;
    for (int n = 2; n < M; n++)
        if (isPerfect(n))
            perfects.push_back(n);
    return perfects;
}
vector<int> primeNumbers(int M)
{
    vector<int> primes;
    for (int n = 2; n < M; n++)
        if (isPrime(n))
            primes.push_back(n);
    return primes;
}
int sumOfVector(vector<int> vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
        sum += vec[i];
    return sum;
}
int main()
{
    int sl = 0;
    int N = 11530;
    int M = largestPrimeFactor(N);
    vector<int> perfects = perfectNumbers(M);
    vector<int> primes = primeNumbers(M);
    cout << "Uoc so nguyen to lon nhat cua " << N << " la = " << M << endl;
    cout << "So hoan hao be hon " << M << " la: ";
    for (int i = 0; i < perfects.size(); i++)
        cout << perfects[i] << " ";
    cout << "\nTong cac so hoan hao be hon " << M << " la: " << sumOfVector(perfects) << endl;
    cout << "\nCac so nguyen to be hon " << M << " la: ";
    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
        sl++;
    }
    cout << endl;
    cout << "Tong so luong cac so nguyen to be hon " << M << " la: " << sl;
    cout << endl;
    cout << "\nTong Cac so nguyen to be hon " << M << " la: " << sumOfVector(primes) << endl;
    return 0;
}
