#include <iostream>
using namespace std;

template <typename T>
class Set {
private:
    T* data;
    int n;

public:
    Set();
    Set(const Set& s);
    ~Set();
    Set& operator=(const Set& s);
    bool contains(const T& x) const;
    bool operator()(const T& x) const;
    Set operator+(const T& x) const;
    Set operator-(const T& x) const;
    Set operator+(const Set& s) const;
    Set operator-(const Set& s) const;
    Set operator*(const Set& s) const;
    void operator[](int index) const;
    friend ostream& operator<<(ostream& out, const Set<T>& s) {
        out << "{ ";
        for (int i = 0; i < s.n; i++) {
            out << s.data[i];
            if (i < s.n - 1) out << ", ";
        }
        out << " }";
        return out;
    }
};
template <typename T>
Set<T> ::Set() {
        n = 0;
        data = NULL;
    }

template <typename T>
Set<T>::Set(const Set& s) {
        n = s.n;
        data = new T[n];
        for (int i = 0; i < n; i++) {
            data[i] = s.data[i];
        }
    }

template <typename T>
Set<T>::~Set() {
        delete[] data;
}

template <typename T>
Set<T>& Set<T>::operator=(const Set& s) {
    if (this != &s) {
        delete[] data;
        n = s.n;
        data = new T[n];
            for (int i = 0; i < n; i++) {
                data[i] = s.data[i];
            }
        }
        return *this;
    }
template <typename T>
bool Set<T>::contains(const T& x) const {
    for (int i = 0; i < n; i++) {
        if (data[i] == x) {
            return true;
        }
        }
        return false;
    }

template <typename T>
bool Set<T>::operator()(const T& x) const {
        return contains(x);
    }

template <typename T>
Set<T> Set<T>::operator+(const T& x) const {
    Set<T> temp(*this);
    if (!temp.contains(x)) {
        T* newData = new T[temp.n + 1];
        for (int i = 0; i < temp.n; i++) {
            newData[i] = temp.data[i];
        }
            newData[temp.n] = x;
            delete[] temp.data;
            temp.data = newData;
            temp.n++;
        }
        return temp;
    }

template <typename T>
    Set<T> Set<T>::operator-(const T& x) const {
        Set<T> temp;
        for (int i = 0; i < n; i++) {
            if (data[i] != x) {
                temp = temp + data[i];
            }
        }
        return temp;
    }

template <typename T>
    Set<T> Set<T>::operator+(const Set& s) const {
        Set<T> result(*this);
        for (int i = 0; i < s.n; i++) {
            result = result + s.data[i];
        }
        return result;
    }

template <typename T>
Set<T> Set<T>::operator-(const Set& s) const {
        Set<T> result(*this);
        for (int i = 0; i < s.n; i++) {
            result = result - s.data[i];
        }
        return result;
    }

template <typename T>
    Set<T> Set<T>::operator*(const Set& s) const {
        Set<T> result;
        for (int i = 0; i < n; i++) {
            if (s.contains(data[i])) {
                result = result + data[i];
            }
        }
        return result;
    }

template <typename T>    
    void Set<T>::operator[](int index) const {
        if (index >= 0 && index < n) {
            cout << data[index] << " ";
        } else {
            cout << "Khong co gia tri nay!" << endl;
        }
    }



int main() {
    Set<int> A;
    A = A + 1 + 2 + 3;
    Set<int> B;
    B = B + 2 + 3 + 4;

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;

    cout << "Hop: " << (A + B) << endl;
    cout << "Hieu: " << (A - B) << endl;
    cout << "Giao: " << (A * B) << endl;

    cout << "2 thuoc A ? " << (A(2) ? " Co" : " Khong") << endl;
    cout << "Phan tu thu 0 cua A: ";
    A[0];
    cout << endl;

    return 0;
}
