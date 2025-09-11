#include <bits/stdc++.h>

using namespace std;

void mangdong(int* &a, int n) {
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
void show(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void insertionsort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubblesort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void sellsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void quicksort(int a[], int l, int r) {
    int i = l, j = r;
    int x = a[(l + r) / 2];
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) quicksort(a, l, j);
    if (i < r) quicksort(a, i, r);
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void merge(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

void search_binary(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            cout << "Tim thay o vi tri: " << mid << endl;
            return;
        } else if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << "Khong tim thay" << endl;
}

typedef void (*SortFn)(int[], int);

void quicksort_wrap(int a[], int n) { if (n > 0) quicksort(a, 0, n - 1); }
void mergesort_wrap(int a[], int n) { if (n > 0) mergesort(a, 0, n - 1); }

int main() {
    int* a = nullptr;
    int n, choice, x;
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap mang: ";
    mangdong(a, n);

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. In mang\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Bubble Sort\n";
        cout << "5. Sell Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Heap Sort\n";
        cout << "8. Merge Sort\n";
        cout << "9. Tim kiem nhi phan\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Mang hien tai: ";
                show(a, n);
                break;
            case 2: {
                SortFn f = selectionsort;
                f(a, n);
                cout << "Da sap xep bang Selection Sort: ";
                show(a, n);
                break;
            }
            case 3: {
                SortFn f = insertionsort;
                f(a, n);
                cout << "Da sap xep bang Insertion Sort: ";
                show(a, n);
                break;
            }
            case 4: {
                SortFn f = bubblesort;
                f(a, n);
                cout << "Da sap xep bang Bubble Sort: ";
                show(a, n);
                break;
            }
            case 5: {
                SortFn f = sellsort;
                f(a, n);
                cout << "Da sap xep bang Shell Sort: ";
                show(a, n);
                break;
            }
            case 6: {
                SortFn f = quicksort_wrap;
                f(a, n);
                cout << "Da sap xep bang Quick Sort: ";
                show(a, n);
                break;
            }
            case 7: {
                SortFn f = heapsort;
                f(a, n);
                cout << "Da sap xep bang Heap Sort: ";
                show(a, n);
                break;
            }
            case 8: {
                SortFn f = mergesort_wrap;
                f(a, n);
                cout << "Da sap xep bang Merge Sort: ";
                show(a, n);
                break;
            }
            case 9:
                cout << "Nhap gia tri can tim: ";
                cin >> x;                {
                    void (*searchFn)(int[], int, int) = search_binary;
                    searchFn(a, n, x);
                }
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    delete[] a;
    return 0;
}