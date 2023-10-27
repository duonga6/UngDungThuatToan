#include <iostream>
using namespace std;

void xuat(int *x, int k) {
	for (int i = 1; i <= k; i++)
		cout << x[i];
	cout << endl;
}

void next(int *x, int k, int i) {
	x[i] += 1;
	i++;
	while (i <= k) {
		x[i] = x[i - 1] + 1;
		i++;
	}
}

void sinh_tap_con(int n, int k) {
	int *x = new int[k + 1], i;
	for (i = 1; i <= k; i++)
		x[i] = i;
	do {
		xuat(x, k);
		i = k;
		while (i > 0 && x[i] == n - k + i)
			i--;
		if (i > 0)
			next(x, k, i);
	} while (i > 0);
}

int main() {
	int n, k;
	cout << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;
	
	sinh_tap_con(n, k);
	
	return 0;
}
