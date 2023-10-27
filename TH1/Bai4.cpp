#include <iostream>
using namespace std;

string a[7] = {"", "Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};

void xuat(int *x) {
	for (int i = 1; i <= 4; i++)
		cout << a[x[i]] << " ";
	cout << endl;
}

void next(int *x, int i) {
	x[i] += 1;
	i++;
	while (i <= 4) {
		x[i] = x[i - 1] + 1;
		i++;
	}
}

void sinh_day_con() {
	int *x = new int[5], i;
	for (i = 1; i <= 4; i++)
		x[i] = i;
	do {
		xuat(x);
		i = 4;
		while (i > 0 && x[i] == 6 - 4 + i)
			i--;
		if (i > 0)
			next(x, i);
	} while (i > 0);
}

int main() {
	
	sinh_day_con();
	
	return 0;
}
