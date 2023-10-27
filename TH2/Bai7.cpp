#include <iostream>
using namespace std;

int n;
int *x = new int[n + 1];

void show(int *x) {
	for (int i = 1; i <= n; i++)
		cout << x[i];
	cout << endl;
}

void Try(int k) {
	for (int i = 0; i <= 1; i++) {
		x[k] = i;
		if (k == n)
			show(x);
		else
			Try(k + 1);
	}
	
}

int main() {
	
	n = 3;
	Try(1);
	
	return 0;
}
