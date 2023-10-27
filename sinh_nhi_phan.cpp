#include <iostream>
using namespace std;

void out(int *a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i];
	cout << endl;
}

void next(int *a, int n, int i) {
	a[i] = 1;
	while (i < n - 1) {
		a[i + 1] = 0;
		i++;
	}
}

void sinh_nhi_phan(int n) {
	int a[n];
	for (int i = 0; i < n; i++)
		a[i] = 0;
	int i = n - 1;
	do {
		out (a, n);
		if (a[i] == 0) {
			next(a, n, i);
			i++;
		}
		i--;
	} while(i > -1);
}


int main() {
	sinh_nhi_phan(4);
	return 0;
}
