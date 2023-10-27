#include <iostream>
using namespace std;

void inp(float *a, int n) {
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void out(float *a, int n) {
	for (int i = 0; i < n; i++) 
		cout << a[i] << " ";
}

int main() {
	int n;
	cin >> n;
	float a[n];
	inp(a, n);
	out(a, n);
	return 0;
}
