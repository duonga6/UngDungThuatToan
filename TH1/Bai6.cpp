#include <iostream>
using namespace std;

string a[7] = {"", "Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};

void xuat(int *x) {
	for (int i = 1; i <= 6; i++)
		cout << a[x[i]] << " ";
	cout << endl;
}

void swap(int &a, int &b) {
	int tg = a;
	a = b;
	b = tg;
}

void next(int *x, int i) {
	int k = 6;
	while (x[k] < x[i])
		k--;
	swap(x[k], x[i]);
	i++;
	int j = 6;
	while (i < j) {
		swap(x[i], x[j]);
		i++;
		j--;
	}
}

void sinh_hoan_vi() {
	int *x = new int[7], i;
	for (i = 0; i <= 6; i++)
		x[i] = i;
	do {
		xuat(x);
		i = 5;
		while (i > 0 && x[i] > x[i + 1])
			i--;
		if (i > 0)
			next(x, i);
	} while (i > 0);
}

int main() {
	
	sinh_hoan_vi();
	return 0;
}
