#include <iostream>
using namespace std;

void xuat(int *x, int k) {
	for (int i = 1; i <= k; i++)
		cout << x[i] << " ";
	cout << endl;
}

void next(int *x, int i, int k) {
	x[i]++;
	i++;
	while (i <= k) {
		x[i] = x[i - 1] + 1;
		i++;
	}
}

void sinh_tapcon(int n, int k) {
	int x[k + 1], i;
	for (i = 1; i <= k; i++)
		x[i] = i;
	do {
		xuat(x, k);
		i = k;
		while (i > 0 && x[i] == n - k + i)
			i--;
		if (i > 0)
			next(x, i, k);
	} while (i > 0);
}

int main() {
	sinh_tapcon(6, 4);
	return 0;
}
