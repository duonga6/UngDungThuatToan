#include <iostream>
using namespace std;

void xuat(int *x, int k) {
	for (int i = 1; i <= k; i++)
		cout << x[i] << " ";
	cout << endl;
}

void next(int i, int *x, int k) {
	x[i]++;
	i++;
	while (i <= k) {
		x[i] = x[i - 1] + 1;
		i++;
	}
}

void tapcon(int k, int n) {
	int x[k + 1], i;
	for (i = 1; i <= k; i++)
		x[i] = i;
	do {
		xuat(x, k);
		i = k;
		while (i > 0 && x[i] == n - k + i)
			i--;
		if (i > 0)
			next(i, x, k);
	} while (i > 0);
}

int main() {
	tapcon(4, 6);
	return 0;
}
