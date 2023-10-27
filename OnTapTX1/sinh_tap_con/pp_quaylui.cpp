#include <iostream>
using namespace std;

int *a;

void xuat(int a[], int k) {
	for (int i = 1; i <= k; i++)
		cout << a[i] << " ";
	cout << endl;
}

void Try(int i, int n, int k) {
	for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		if (i == k)
			xuat(a, k);
		else
			Try(i + 1, n, k);
	}
}

int main() {
	int n = 6, k = 4;
	a = new int[k + 1];
	for (int i = 0; i <= k; i++)
		a[i] = 0;
	Try(1, n, k);	
		
	return 0;
}
