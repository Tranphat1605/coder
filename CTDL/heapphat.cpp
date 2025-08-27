#include <iostream> 

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b; 
	b = tmp;
}

void max_heap(int a[], int n, int i) {
	int l = 2*i+1;
	int r = 2*i+2;
	int lar = i;
	if (r < n && a[r] > a[lar]) lar = r;
	if (l < n && a[l] > a[lar]) lar = l;
	if (lar != i) {
		swap(a[lar], a[i]);
		max_heap(a, n, lar);
	}
}

void build(int a[], int n) {
	for (int i = (n-1)/2; i >= 0;i--) {
		max_heap(a, n, i);
	}
}

void show(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void sort(int a[], int n) {
	build(a,n);
	for (int i = n-1; i > 0; i--) {
		swap(a[0], a[i]);
		max_heap (a, i, 0);
	}
}

int main () {
	int a[8] = {9, 3, 1, 7, 4, 6, 5, 2};
	sort(a, 8);
	show(a, 8);
	return 0;
}


