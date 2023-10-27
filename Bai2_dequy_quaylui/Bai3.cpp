#include <iostream>
using namespace std;

void xuat(string *x, int *a) {
	for (int i = 1; i <= 6; i++)
		cout << x[a[i]] << " ";
	cout << endl;
}

void swap(int &a, int &b) {
	int tg = a;
	a = b;
	b = tg;
}

void next(int *a, int i) {
	int k = 6;
	while (a[k] < a[i])
		k--;
	swap(a[k], a[i]);
	i++;
	int j = 6;
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

void liet_ke(string *x) {
	int *a = new int[7], i;
	for (i = 1; i <= 6; i++)
		a[i] = i;
	do {
		xuat(x, a);
		i = 5;
		while (i > 0 && a[i] > a[i + 1])
			i--;
		if (i > 0)
			next(a, i);
	} while (i > 0);
}

int main() {
	string x[7] = {"", "tam", "toan", "trang", "cong", "trung", "tu"};
	liet_ke(x);
	
	return 0;
}
