#include <iostream>
using namespace std;

double Pow(float a, int n) {
	if (n == 0)
		return 1;
	double x = Pow(a, n / 2);
	if (n % 2 == 0)
		return x*x;
	else
		return a * x * x;
}

int main() {
	float a;
	int n;
	cout << "a = ";	cin >> a;
	cout << "n = ";	cin >> n;
	cout << "a^n = " << Pow(a, n);
	
	return 0;
}
