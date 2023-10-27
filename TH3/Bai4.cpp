#include <iostream>
using namespace std;

double pow(double a, int n) {
	if (n == 1)
		return a;
	double x = pow(a, n / 2);
	if (n % 2 == 0)
		return x * x;
	else
		return x * x * a;
}

int main() {
	double a;
	int n;
	cout << "a = "; cin >> a;
	cout << "n = "; cin >> n;
	
	cout << "a^n = " << pow(a, n);
	
	return 0;	
}
