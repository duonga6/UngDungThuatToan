#include <iostream>
using namespace std;

void show(int *x, int n) {
	for (int i = 1; i <= n; i++)
		cout << x[i];
	cout << endl;
}

void next(int *x, int n, int i) {
	x[i] = 1;
	i++;
	while (i <= n) {
		x[i] = 0;
		i++;
	}
}

void sinh_day_nhi_phan(int n) {
	int *x = new int[n+1], i;
	for (i = 1; i <= n; i++)
		x[i] = 0;
		
	do {
		show(x, n);
		i = n;
		while (i > 0 && x[i] == 1)
			i--;
		if (i > 0)
			next(x, n, i);
	} while (i > 0);
} 

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	
	sinh_day_nhi_phan(n);
	
	return 0;
}
