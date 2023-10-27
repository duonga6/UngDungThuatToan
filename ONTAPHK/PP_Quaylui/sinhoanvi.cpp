#include <iostream>
using namespace std;

int *dd;
int *x;

void xuat(int n) {
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void Try(int k, int n) {
	for (int i = 1; i <= n; i++) {
		if (dd[i] == 0) {
			x[k] = i;
			if (k == n) {
				xuat(n);
			} else {
				dd[i] = 1;
				Try(k + 1, n);
				dd[i] = 0;
			}
		}
	}
}

int main() {
	int n = 4;
	x = new int [n + 1];
	dd = new int [n + 1];
	for (int i = 0; i <= n; i++)
		dd[i] = 0;
		
	Try(1, n);
}
