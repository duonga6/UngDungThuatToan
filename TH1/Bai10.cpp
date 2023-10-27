#include <iostream>
using namespace std;

void nhap(int *x, int n) {
	for (int i = 0; i < n; i++) {
		cout << "x["<<i<<"] = ";
		cin >> x[i];
	}
}

long tong_le(int *x, int n) {
	if (n < 0) 
		return 0;
	if (x[n] % 2 == 1)
		return x[n] + tong_le(x, n - 1);
	else
		return tong_le(x, n - 1);
}

int main() {
	int n;
	cout << "So pt cua day: ";
	cin >> n;
	
	int *x = new int[n];
	nhap(x, n);
	
	cout << "Tong cac so le: " << tong_le(x, n - 1);
	return 0;
}
