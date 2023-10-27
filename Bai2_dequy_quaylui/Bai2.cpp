#include <iostream>
using namespace std;

void xuat(string *x, int *a) {
	for (int i = 1; i <= 4; i++)
		cout << x[a[i]] << " ";
	cout << endl;
}

void next(int *a, int i) {
	a[i] += 1;
	i++;
	while (i <= 4) {
		a[i] = a[i - 1] + 1;
		i++;
	}
}

void liet_ke(string *x) {
	int *a = new int[5], i;
	for (i = 1; i <= 4; i++)
		a[i] = i;
	do {
		xuat(x, a);
		i = 4;
		while (i > 0 && a[i] == 6 - 4 + i)
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
