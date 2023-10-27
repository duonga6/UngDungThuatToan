#include <iostream>
using namespace std;

int *a;

void xuat(int k) {
	for (int i = 1; i <= k; i++)
		cout << a[i] << " ";
	cout << endl;
}

void Try(int i, int k, int n) {
	for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		if (i == k)
			xuat(k);
		else
			Try(i + 1, k, n);
	}
}

int main() {
	int n = 5;
	int k = 3;
	a = new int[n + 1];
	a[0] = 0;
	
	Try(1, k, n);
	
	return 0;
}
