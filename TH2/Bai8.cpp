#include <iostream>
using namespace std;

int n;
int *x = new int[n + 1];
int *dd = new int[n + 1];

void show(int *x) {
	for (int i = 1; i <= n; i++)
		cout << x[i];
	cout << endl;
}

void Try(int k) {
	for (int i = 1; i <= n; i++) {
		if (dd[i] == 0) {
			x[k] = i;
			if (k == n)
				show(x);
			else {
				dd[i] = 1;
				Try(k + 1);
				dd[i] = 0;
			}
		}
	}
}

int main() {
	n = 4;
	for (int i = 1; i <= n; i++){
		dd[i] = 0;
	}
		
	Try(1);
	
	return 0;
}
