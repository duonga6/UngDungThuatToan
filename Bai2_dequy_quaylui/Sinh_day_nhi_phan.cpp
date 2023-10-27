#include <iostream>

using namespace std;

//kieu 1
void xuat(int *x, int n) {
	for (int i = 1; i <= n; i++) 
		cout << x[i] << " ";
	cout << endl;
}

void next(int *x, int n, int z) {
	x[z] = 1;
	z++;
	while (z <= n) {
		x[z] = 0;
		z++;
	}
}

void sinh_day_nhi_phan(int n) {
	int *x = new int[n + 1];
	int z;
	for (int i = 1; i <= n; i++)
		x[i] = 0;
	do {
		xuat(x, n);
		z = n;
		while (z > 0 && x[z] == 1)
			z--;
		if (z > 0)
			next(x, n, z);
	} while (z > 0);
}

//kieu2

void xuat2(int *x, int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void next2(int *x, int n, int z) {
	x[z] = 1;
	while (z < n - 1) {
		x[z + 1] = 0;
		z++;
	}
}

void sinh_day_nhi_phan2(int n) {
	int *x = new int[n];
	for (int i = 0; i < n; i++)
		x[i] = 0;
	int z;
	do {
		xuat2(x, n);
		z = n - 1;
		while (z > -1 && x[z] == 1)
			z--;
		if (z > - 1)
			next2(x, n, z);
	} while (z > -1);
}

int main() {
	sinh_day_nhi_phan2(4);
	return 0;
}
