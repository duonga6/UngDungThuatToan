#include <iostream>
using namespace std;

void xuat(int *x, int n) {
	for (int i = 1; i <= n; i++)
		cout << x[i];
	cout << endl;
}

void swap(int &x, int &y) {
	int tg = x;
	x = y;
	y = tg;
}

void next(int *x, int n, int i) {
	int k = n;
	while (x[k] < x[i])
		k--;
	swap(x[k], x[i]);
	i++;
	int j = n;
	while (i < j) {
		swap(x[i], x[j]);
		i++;
		j--;
	}
}

void sinh_hoan_vi(int n) {
	int *x = new int[n + 1], i;
	for (i = 0; i <= n; i++)
		x[i] = i;
	do {
		xuat(x, n);
		i = n - 1;
		while (i > 0 && x[i] > x[i + 1])
			i--;
		if (i > 0)
			next(x, n, i);
	} while (i > 0);
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	sinh_hoan_vi(n);
	
	return 0;
}
