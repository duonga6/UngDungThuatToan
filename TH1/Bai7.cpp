#include <iostream>
using namespace std;

int n;
int *d = new int[n + 1];

long f(int n) {
	if (n < 3)
		return 1;
	else
		return f(n - 1) + f(n - 2);
}

long fi(int n) {
	if (n < 3)
		d[n] = 1;
	else if (d[n] < 0)
		d[n] = fi(n - 1) + fi(n - 2);
	
	return d[n];
}

int main() {
	
	cout << "n = ";
	cin >> n;
	
	d[n] = -1;
	cout << f(n) << endl;
	cout << fi(n) << endl;
	
	return 0;
}
