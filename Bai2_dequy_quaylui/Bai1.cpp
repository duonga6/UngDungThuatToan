#include <iostream>
using namespace std;

void xuat(char *x, int n) {
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void next(char *x, int n, int i) {
	x[i] = 'b';
	i++;
	while (i <= n) {
		x[i] = 'a';
		i++;
	}
}

void sinh_chuoi(int n) {
	char *x = new char[n + 1], i;
	for (i = 1; i <= n; i++)
		x[i] = 'a';
	do {
		xuat(x, n);
		i = n;
		while (i > 0 && x[i] == 'b')
			i--;
		if (i > 0)
			next(x, n, i);
	} while (i > 0);
}

int main() {
	sinh_chuoi(4);
	return 0;
}
