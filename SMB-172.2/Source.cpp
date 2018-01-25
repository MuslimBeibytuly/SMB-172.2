#include <iostream>
#include <cstdlib>
using namespace std;
void merge(int *a, int n, int l, int m, int h, int *b);
void divide(int *a, int n, int l, int h, int *b);
void insertSort(int *a, int n, int *b) {
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}
void mergeSort(int *a, int n, int *b) {
	divide(a, n, 0, n - 1, b);
}
void divide(int *a, int n, int l, int h, int *b) {
	int m;
	if (l < h) {
		m = (l + h) / 2;
		divide(a, n, l, m, b);
		divide(a, n, m + 1, h, b);
		merge(a, n, l, m, h, b);
		for (int i = l; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
		for (int i = m + 1; i < h; i++) {
			cout << a[i] << ' ';
		}
		cout << endl << endl;
	}
	
}
void merge(int *a, int n, int l, int m, int h, int *b) {
	int p1 = l, p2 = m + 1, i;
	for (i = l; p1 <= m && p2 <= h; ++i) {
		if (a[p1] <= a[p2]) {
			b[i] = a[p1++];
		}
		else {
			b[i] = a[p2++];
		}
	}

	while (p1 <= m) {
		b[i++] = a[p1++];
	}
	while (p2 <= h) {
		b[i++] = a[p2++];
	}

	for (i = l; i < h; ++i) {
		a[i] = b[i];
	}
}

int main() {
	int n;
	cin >> n;

	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
		cout << a[i] << ' ';
		b[i] = 0;
	}
	cout << endl;
	//insertSort(a, n);
	mergeSort(a, n, b);
	for (int i = 0; i < n; i++) {
		cout << b[i] << '\t';
	}
	cout << endl;
	delete[] a;
	system("pause");
	return 0;
}